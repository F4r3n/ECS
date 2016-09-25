#include "SystemManager.h"
#include "EntityManager.h"
System* currentSystem = nullptr;
float currentTime = 0;

void call_back_init(Entity *e) {
    currentSystem->init(e);
}

void call_back_update(Entity *e) {
    currentSystem->update(currentTime, e);
}

void SystemManager::init(EntityManager& em) {
    for(auto s : systems) {
        currentSystem = s.get();
        std::vector<const std::type_info*> compo = s->getComponentsNeeded();
        std::bitset<MAX_COMPONENTS> bits;
        ComponentTypeManager::getBitSets<MAX_COMPONENTS>(bits, compo);
        //std::function<void(Entity*)> call_back_function = SystemManager::call_back;
        em.getEntitiesWithComponents(&call_back_init, bits);
     
    }
    EntityManager::get().make();
}

void SystemManager::update(float dt, EntityManager& em)
{
    currentTime = dt;
    for(auto s : systems) {
        s->pre_update();
        currentSystem = s.get();
        std::vector<const std::type_info*> compo = s->getComponentsNeeded();
        std::bitset<MAX_COMPONENTS> bits;
        ComponentTypeManager::getBitSets<MAX_COMPONENTS>(bits, compo);
        em.getEntitiesWithComponents(&call_back_update, bits);
     
        s->over();
        EntityManager::get().make();
    }
}