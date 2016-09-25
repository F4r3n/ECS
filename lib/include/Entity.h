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
    bool active = false;
    bool toCreate = true;
    template <typename T> T* addComponent(Component<T> *c = new T())
    {
       return EntityManager::get().addComponent<T>(this, c);
    }

    template <typename T> T* get()
    {
        return EntityManager::get().get<T>(this);
    }
    
    void destroy();
private:
};

#endif
