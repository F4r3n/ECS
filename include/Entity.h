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

        template <typename T>
            void addComponent(std::shared_ptr<T> component) {
                components.push_back(component);
            }

        template <typename T>
            std::shared_ptr<T> getComponent() {
                for(std::shared_ptr<Component> c : components) {
                    if(std::dynamic_pointer_cast<T>(c)) return std::dynamic_pointer_cast<T>(c);
                }
                return nullptr;
            }
    private:
        int id;
        std::vector<std::shared_ptr<Component>> components;
};


#endif
