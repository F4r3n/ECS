#include "EntityManager.h"
#include "Entity.h"
int EntityManager::ids = 0;

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

EntityManager::~EntityManager()
{
}

std::shared_ptr<Entity> EntityManager::createEntity()
{
    entities_alive.push_back(std::make_shared<Entity>(free_id.back()));
    free_id.pop_back();
    std::shared_ptr<Entity> e = entities_alive.back();
    
    return e;
}

std::vector<std::shared_ptr<Entity> > EntityManager::getEntities()
{
    std::vector<std::shared_ptr<Entity> > temp;
    for(std::shared_ptr<Entity> e : entities_alive)
        if(isExists(e->ID))
            temp.push_back(e);

    return temp;
}

size_t EntityManager::getID(Entity *e) {
    return e->ID;
}


