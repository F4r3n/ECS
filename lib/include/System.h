#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <string>
#include <memory>
#include <bitset>
#include "Config.h"
class ComponentManager;
class Entity;
class EntityManager;
class System
{

public:
    System()
    {
    }
    virtual ~System()
    {
    }
    virtual void pre_update() = 0;
    virtual void update(float dt, Entity* e) = 0;
    virtual void init(Entity* e) = 0;
    virtual void over() = 0;
    friend class SystemManager;
    template <typename T> void addComponent()
    {
        componentsNeeded.push_back(T::id());
        bits.flip(T::id());
    }
    std::vector<size_t> getComponentsNeeded() const {
        return componentsNeeded;
    }
    
    std::bitset<MAX_COMPONENTS>& getMask(){
        return bits;
    }

private:
    std::vector<size_t> componentsNeeded;
    std::bitset<MAX_COMPONENTS> bits;
};

#endif
