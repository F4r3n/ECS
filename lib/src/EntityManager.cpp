#include "EntityManager.h"
#include "Entity.h"
#include <cassert>

EntityManager EntityManager::em;

EntityManager::EntityManager()
{
    free_id.resize(POOL_SIZE);
    for(size_t i = 0; i < free_id.size(); ++i) {
        free_id[i] = free_id.size() - i - 1;
    }
}

EntityManager& EntityManager::get()
{
    return em;
}

EntityManager::~EntityManager()
{
}

bool EntityManager::isExists(size_t id)
{
    return ((id < entities_alive.size()) && (entities_alive[id]->ID != -1));
}

void EntityManager::destroyEntity(size_t id)
{
    entities_killed.push_back(id);
    entities_alive[id]->ID = -1;
}

void EntityManager::refresh()
{
    for(int i : entities_killed)
        free_id.push_back(i);

    entities_killed.clear();
}



pEntity EntityManager::createEntity()
{
    entities_alive.push_back(std::make_shared<Entity>(free_id.back()));
    free_id.pop_back();
    pEntity e = entities_alive.back();

    return e;
}

std::vector<pEntity> EntityManager::getEntities()
{
    std::vector<pEntity> temp;
    for(pEntity e : entities_alive)
        if(isExists(e->ID))
            temp.push_back(e);

    return temp;
}

std::vector<size_t> EntityManager::getEntitiesAlive()
{
    std::vector<size_t> temp;
    for(pEntity e : entities_alive)
        if(isExists(e->ID))
            temp.push_back(e->ID);

    return temp;
}

bool EntityManager::hasComponents(std::shared_ptr<Entity> e, std::vector<std::string>& compo)
{
    if(entitiesComponents[e->ID]) {
        for(std::string c : compo) {
            if(!entitiesComponents[e->ID]->has(c))
                return false;
        }
        return true;
    }
    return false;
}

bool EntityManager::hasComponents(std::shared_ptr<Entity> e, std::bitset<MAX_COMPONENTS>& bits)
{
    if(entitiesComponents[e->ID])
        return entitiesComponents[e->ID]->has(bits);
}

void EntityManager::deleteEntity(Entity* e)
{
    assert(e);
    destroyEntity(e->ID);
    if(entitiesComponents[e->ID]) {
        entitiesComponents[e->ID].reset();
    }
}

size_t EntityManager::getID(Entity* e)
{
    return e->ID;
}
