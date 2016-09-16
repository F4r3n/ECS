#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <string>
#include <memory>
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

    virtual void update(float dt, std::shared_ptr<Entity> e) = 0;
    virtual void init() = 0;
    friend class SystemManager;
    template <typename T> void addComponent()
    {
        componentsNeeded.push_back(T::id());
    }
    std::vector<std::string> getComponentsNeeded() const {
        return componentsNeeded;
    }

private:
    std::vector<std::string> componentsNeeded;
};

#endif