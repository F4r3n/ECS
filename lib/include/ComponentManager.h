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
    ComponentManager() {}
    ~ComponentManager() {}

    template <typename T> T* getComponent()
    {
        if(components.find(T::id()) == components.end()) {
            return nullptr;
        }
        return dynamic_cast<T*>(components[T::id()].get());
    }

    template <typename T> T* addComponent(Component<T> *c)
    {
        bits.set(ComponentTypeManager::registerComponent(typeid(T)), 1);
        components[T::id()].reset(c);
        std::cout <<"Component "<< dynamic_cast<T*>(components[T::id()].get()) << std::endl;

        return dynamic_cast<T*>(components[T::id()].get());
    }

    bool has(std::string value)
    {
        if(components.find(value) != components.end())
            return true;
        return false;
    }
    
    bool has(std::bitset<MAX_COMPONENTS> &compo) {
        return ((bits & compo)  == compo);
    } 

private:
    std::bitset<MAX_COMPONENTS> bits;
    std::unordered_map<std::string, std::unique_ptr<BaseComponent> > components;
};

#endif
