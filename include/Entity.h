#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <iostream>
#include <typeinfo>
#include <memory>

#include "EntityManager.h"
#include "Component.h"

class Entity
{

public:
    Entity();
    Entity(size_t ID);
    ~Entity();
    size_t ID;

    template <typename T> void addComponent(std::shared_ptr<Component<T> > c)
    {
        auto entitiesComponents = EntityManager::get().getEntitiesComponents();
        if(entitiesComponents[ID] != nullptr) {
            entitiesComponents[ID]->addComponent<T>(c);
        }
    }

private:
};

#endif
