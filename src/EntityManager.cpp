#include "EntityManager.h"
int EntityManager::ids = 0;


EntityManager::EntityManager() {}

EntityManager::~EntityManager() {}

Entity* EntityManager::createEntity() {
    Entity *e = new Entity(ids);
    entities.push_back(e);
    ids++;
    return e;
}

std::vector<Entity*>& EntityManager::getEntities() {
    return entities;
}
