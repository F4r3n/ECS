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
                if(components.find(T::id()) == components.end()) return nullptr;
                return std::dynamic_pointer_cast<T>(components[T::id()]);
            }


        template <typename T>
            bool addComponent(std::shared_ptr<Component<T>> c) {
              if(components.find(T::id()) !=  components.end()) return false;
              components[T::id()] = c;
              return true;
            }

    private:

        std::map<size_t, std::shared_ptr<BaseComponent> > components; 
        std::map<std::string, int> IDComponents;

        int id = 0;

};

#endif
