#ifndef ENTITY_H
#define ENTITY_H
#include "Component.h"
#include <vector>
#include <iostream>
#include <typeinfo>
#include <memory>

class Entity {
    public:
        Entity();
        Entity(int id);
        int getId();
        ~Entity();

    private:
        int id;
        std::vector<std::shared_ptr<Component>> components;
};


#endif
