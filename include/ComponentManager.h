#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "Component.h"
#include <vector>
#include <memory>
#include <unordered_map>
#include <typeinfo>
#include <array>
#include <iostream>
#define MAX_COMPONENTS 100

class ComponentManager {
    public:
        ComponentManager();

        template <typename T>
            std::shared_ptr<T> getComponent() {
                if(components.find(T::id()) == components.end()) return nullptr;
                return std::dynamic_pointer_cast<T>(components[T::id()]);
            }


        template <typename T>
            bool addComponent(std::shared_ptr<Component<T>> c) {
             
              components[T::id()] = c;
              return true;
            }

    private:

        std::unordered_map<std::string, std::shared_ptr<BaseComponent> > components; 


};

#endif
