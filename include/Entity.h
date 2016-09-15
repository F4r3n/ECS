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
        EntityManager::get().addComponent<T>(this, c);
    }

private:
};

#endif
