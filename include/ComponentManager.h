#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "Component.h"
#include <vector>
#include <memory>
#include <map>
#include <typeinfo>
#include <array>
#include <iostream>
#define MAX_COMPONENTS 1000

class ComponentManager {
    public:
        ComponentManager();

        template <typename T>
            std::shared_ptr<T> getComponent(int entityId) {
                if(IDComponents.find(typeid(T).name()) != IDComponents.end()) 
                    for(std::shared_ptr<Component> c : components[IDComponents[typeid(T).name()]]) 
                        if(c->entityId == entityId) return std::dynamic_pointer_cast<T>(c);
                return nullptr;
            }


        template <typename T>
            void addComponent(std::shared_ptr<Component> c) {
                if(IDComponents.find(typeid(T).name()) == IDComponents.end()) 
                          IDComponents[typeid(T).name()] = id++;


                for(auto co :  components[IDComponents[typeid(T).name()]]) {
                    if(co->entityId == c->entityId) std::cout << "Entity owns already this component" << std::endl;
                    return;
                }

                    components[IDComponents[typeid(T).name()]].push_back(c);
            }

        template <typename T>
        std::vector<std::shared_ptr<Component>> getComponents() {
            return components[IDComponents[typeid(T).name()]];
        }


    private:
        std::array<std::vector<std::shared_ptr<Component>>,MAX_COMPONENTS > components; 
        std::map<std::string, int> IDComponents;

        int id = 0;

};

#endif
