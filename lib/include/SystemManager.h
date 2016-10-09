#pragma once
#include "System.h"
#include <memory>
#include <typeinfo>
#include <cassert>
#include "EntityManager.h"
#include "Event.h"
class SystemManager {
public:
    SystemManager() {
    }
    ~SystemManager() {
    }

    void addSystem(std::shared_ptr<System> system) {
        systems.push_back(system);
    }

    template <typename T> std::shared_ptr<T> getSystem(int index) {
        if(index >= systems.size())
            return nullptr;
        return std::dynamic_pointer_cast<T>(systems[index]);
    }

    void update(float dt, EntityManager& em, EventManager &event);
    void init(EntityManager& em, EventManager &event);
    //void call_back(Entity *e);

private:
    std::vector<std::shared_ptr<System> > systems;
};
