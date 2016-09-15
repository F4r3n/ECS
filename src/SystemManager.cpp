#include "SystemManager.h"
#include "EntityManager.h"

void SystemManager::update(float dt, EntityManager& em)
{
    for(auto s : systems) {
        std::vector<std::string> compo = s->getComponentsNeeded();
        for(std::shared_ptr<Entity> e : em.getEntities()) {

            if(em.hasComponent(e, compo))
                s->update(dt, e);
        }
    }
}