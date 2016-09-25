#include "EntityManager.h"
#include "Entity.h"
#include <cassert>
//#include <iostream>
EntityManager EntityManager::em;

EntityManager::EntityManager() {
    free_id.resize(POOL_SIZE);
    for(size_t i = 0; i < free_id.size(); ++i) {
        free_id[i] = free_id.size() - i - 1;
    }
}

EntityManager& EntityManager::get() {
    return em;
}

EntityManager::~EntityManager() {
}

bool EntityManager::isExists(size_t id) {
    return (id < entities_alive.size() && entities_alive[id] &&
            (entities_alive[id]->ID != std::numeric_limits<size_t>::max()));
}

void EntityManager::destroyEntity(size_t id, bool isActive) {
    entities_killed.push_back(id);
    if(isActive)
        entities_alive[id]->ID = std::numeric_limits<size_t>::max();
}

void EntityManager::make() {
    if(temp_entities.empty())
        return;
    for(pEntity& e : temp_entities) {
        if(e->toCreate == false)
            continue;
        e->active = true;
        entities_alive.push_back(std::move(e));
    }
    temp_entities.clear();
}

void EntityManager::refresh() {
    for(int i : entities_killed)
        free_id.push_back(i);

    entities_killed.clear();
}

Entity* EntityManager::createEntity() {
    temp_entities.push_back(std::make_unique<Entity>(free_id.back()));
    free_id.pop_back();
    return temp_entities.back().get();
}

void EntityManager::getEntities(std::function<void(Entity*)> func) {
    for(pEntity& e : entities_alive)
        if(isExists(e->ID))
            func(e.get());
}

void EntityManager::getEntitiesWithComponents(std::function<void(Entity*)> func, std::bitset<MAX_COMPONENTS>& bits) {

    for(pEntity& e : entities_alive) {
        if(!e)
            continue;

        if(isExists(e.get()->ID) && hasComponents(e.get(), bits)) {
            func(e.get());
        }
    }
}

std::vector<size_t> EntityManager::getEntitiesAlive() {
    std::vector<size_t> temp;
    for(pEntity& e : entities_alive)
        if(isExists(e->ID))
            temp.push_back(e->ID);

    return temp;
}

bool EntityManager::hasComponents(Entity* e, std::vector<std::string>& compo) {
    if(!e)
        return false;
    if(entitiesComponents[e->ID]) {
        for(std::string c : compo) {
            if(!entitiesComponents[e->ID]->has(c))
                return false;
        }
        return true;
    }
    return false;
}

bool EntityManager::hasComponents(Entity* e, std::bitset<MAX_COMPONENTS>& bits) {
    if(!e)
        return false;
    if(entitiesComponents[e->ID])
        return entitiesComponents[e->ID]->has(bits);
    return false;
}

void EntityManager::deleteEntity(Entity* e) {
    assert(e);
    
    if(entitiesComponents[e->ID]) {
        entitiesComponents[e->ID].reset();
    }
    
    destroyEntity(e->ID, e->active);
    e->toCreate = false;
    e->active = false;
}

size_t EntityManager::getID(Entity* e) {
    return e->ID;
}
