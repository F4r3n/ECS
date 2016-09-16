#include "SystemManager.h"
#include "EntityManager.h"

void SystemManager::update(float dt, EntityManager& em)
{
    for(auto s : systems) {
        std::vector<const std::type_info*> compo = s->getComponentsNeeded();
        std::bitset<MAX_COMPONENTS> bits;
        ComponentTypeManager::getBitSets<MAX_COMPONENTS>(bits, compo);
        std::cout << bits[0] << std::endl;
        for(std::shared_ptr<Entity> e : em.getEntities()) {
            
            if(em.hasComponents(e, bits))
                s->update(dt, e);
        }
    }
}