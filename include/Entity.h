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

        void addComponent(std::shared_ptr<Component> component);
           
        template <typename T>
            void addComponent() {
                components.push_back(std::make_shared<T>());
            }

        template <typename T>
            std::shared_ptr<T> getComponent() {
                for(std::shared_ptr<Component> c : components) {
                    std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
                    if(t) return t;
                }
                return nullptr;
            }
    private:
        int id;
        std::vector<std::shared_ptr<Component>> components;
};


#endif
