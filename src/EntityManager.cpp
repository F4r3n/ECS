#include "EntityManager.h"
int EntityManager::ids = 0;


EntityManager::EntityManager() {
    free_id.resize(POOL_SIZE);
    for(size_t i = 0; i < free_id.size(); ++i) {
        free_id[i] = free_id.size() - i - 1;
    }
}
bool EntityManager::isExists(Entity id) {
    return (id < entities_alive.size() && entities_alive[id] != -1);
}

void EntityManager::destroyEntity(size_t id) {
    entities_killed.push_back(id);
    entities_alive[id] = -1;
}

void EntityManager::refresh() {
    for(int i : entities_killed)
        free_id.push_back(i);

    entities_killed.clear();
}

EntityManager::~EntityManager() {}

Entity EntityManager::createEntity() {
    entities_alive.push_back(Entity(free_id.back()));
    free_id.pop_back();
    return entities_alive.back();
}

std::vector<Entity> EntityManager::getEntities() {
    std::vector<Entity> temp;
    for(Entity e : entities_alive)
        if(isExists(e)) temp.push_back(e);

    return temp;
}
