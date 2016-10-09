#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H
#include "Component.h"
#include <vector>
#include <memory>
#include <unordered_map>
#include <typeinfo>
#include <array>
#include <iostream>
#include <bitset>
#include "Config.h"

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
        bits.set(T::id(), 1);
        components[T::id()].reset(c);
        //std::cout <<"Component "<< dynamic_cast<T*>(components[T::id()].get()) << std::endl;

        return dynamic_cast<T*>(components[T::id()].get());
    }

    template <typename T>
    bool has()
    {
       return bits.test(T::id());
    }
    bool has(size_t id)
    {
       return bits.test(id);
    }
    
    bool has(std::bitset<MAX_COMPONENTS> &compo) const{
        if(!compo.any()) return false;
        return ((bits & compo)  == compo);
    }
    
    void resetMask() {
        bits.reset();
    }

private:
    std::bitset<MAX_COMPONENTS> bits;
    std::unordered_map<size_t, std::unique_ptr<BaseComponent> > components;
};

#endif
