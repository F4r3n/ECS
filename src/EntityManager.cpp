#include "EntityManager.h"
int EntityManager::ids = 0;


EntityManager::EntityManager() {}

EntityManager::~EntityManager() {}

Entity& EntityManager::createEntity() {
    Entity e(ids);
    entities.push_back(e);
    ids++;
    return entities.back();
}
