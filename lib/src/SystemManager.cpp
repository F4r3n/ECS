#include "SystemManager.h"
#include "EntityManager.h"
System* currentSystem = nullptr;
float currentTime = 0;

void call_back_init(Entity* e) {
   // currentSystem->init(e);
}

void call_back_update(Entity* e) {
    //currentSystem->update(currentTime, e);
}

void SystemManager::init(EntityManager& em, EventManager &event) {
    EntityManager::get().make();
    for(auto s : systems) {
        if(!s) continue;
        //currentSystem = s.get();
        //em.getEntitiesWithComponents(&call_back_init, currentSystem->getMask());
        s->init(em, event);
    }
    em.make();
}

void SystemManager::update(float dt, EntityManager& em, EventManager &event) {
    currentTime = dt;
    for(auto s : systems) {
        if(!s) continue;

        s->pre_update(em);
        //currentSystem = s.get();
        //em.getEntitiesWithComponents(&call_back_update, currentSystem->getMask());
        s->update(dt, em, event);
        s->over();
        em.make();
    }
}