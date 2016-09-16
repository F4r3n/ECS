#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H
#include "ComponentTypeManager.h"
#include "Component.h"
#include <vector>
#include <memory>
#include <unordered_map>
#include <typeinfo>
#include <array>
#include <iostream>
#include <bitset>
#define MAX_COMPONENTS 100

class ComponentManager
{
public:
    ComponentManager();

    template <typename T> std::shared_ptr<T> getComponent()
    {
        if(components.find(T::id()) == components.end())
            return nullptr;
        return std::dynamic_pointer_cast<T>(components[T::id()]);
    }

    template <typename T> bool addComponent(std::shared_ptr<Component<T> > c)
    {
        bits.set(ComponentTypeManager::registerComponent(typeid(T)), 1);
        components[T::id()] = c;
        return true;
    }

    bool has(std::string value)
    {
        if(components.find(value) != components.end())
            return true;
        return false;
    }
    
    bool has(std::bitset<MAX_COMPONENTS> &compo) {
        return (compo ^ bits).none();
    } 

private:
    std::bitset<MAX_COMPONENTS> bits;
    std::unordered_map<std::string, std::shared_ptr<BaseComponent> > components;
};

#endif
