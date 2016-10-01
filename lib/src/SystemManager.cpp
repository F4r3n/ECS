#include "SystemManager.h"
#include "EntityManager.h"
System* currentSystem = nullptr;
float currentTime = 0;

void call_back_init(Entity* e) {
    currentSystem->init(e);
}

void call_back_update(Entity* e) {
    currentSystem->update(currentTime, e);
}

void SystemManager::init(EntityManager& em) {
    EntityManager::get().make();
    for(auto s : systems) {
        currentSystem = s.get();
        em.getEntitiesWithComponents(&call_back_init, currentSystem->getMask());
    }
    EntityManager::get().make();
}

void SystemManager::update(float dt, EntityManager& em) {
    currentTime = dt;
    for(auto s : systems) {
        s->pre_update();
        currentSystem = s.get();
        em.getEntitiesWithComponents(&call_back_update, currentSystem->getMask());

        s->over();
        EntityManager::get().make();
    }
}