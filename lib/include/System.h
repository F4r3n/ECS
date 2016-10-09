#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <string>
#include <memory>
#include <bitset>
#include "Config.h"

class EventManager;
class ComponentManager;
class Entity;
class EntityManager;
class System {

public:
    System() {
    }
    virtual ~System() {
    }
    virtual void pre_update(EntityManager &manager) = 0;
    virtual void update(float dt, EntityManager &manager, EventManager &event) = 0;
    virtual void init(EntityManager &manager, EventManager &event) = 0;
    virtual void over() = 0;
    friend class SystemManager;
    template <typename T> void addComponent() {
        componentsNeeded.push_back(T::id());
        bits.flip(T::id());
    }
    std::vector<size_t> getComponentsNeeded() const {
        return componentsNeeded;
    }

    std::bitset<MAX_COMPONENTS>& getMask() {
        return bits;
    }

protected:
    std::bitset<MAX_COMPONENTS> bits;

private:
    std::vector<size_t> componentsNeeded;
};

#endif
