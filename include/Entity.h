#ifndef ENTITY_H
#define ENTITY_H
#include "Component.h"
#include <vector>
#include <iostream>
#include <typeinfo>
class Entity {
    public:
        Entity();
        Entity(int id);
        int getId();
        ~Entity();

        template <typename T>
            void addComponent(T *component) {
                components.push_back(component);
            }

        template <typename T>
            T* getComponent() {
                for(Component *c : components) {
                    if(dynamic_cast<T*>(c)) return dynamic_cast<T*>(c);
                }
                return nullptr;
            }
    private:
        int id;
        std::vector<Component*> components;
};


#endif
