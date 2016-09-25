#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <string>
#include <memory>
#include "ComponentTypeManager.h"
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
        ComponentTypeManager::registerComponent(typeid(T));
        componentsNeeded.push_back(&typeid(T));
    }
    std::vector<const std::type_info*> getComponentsNeeded() const {
        return componentsNeeded;
    }

private:
    std::vector<const std::type_info*> componentsNeeded;
};

#endif
