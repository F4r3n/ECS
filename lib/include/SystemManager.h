#pragma once
#include "System.h"
#include <memory>
#include <typeinfo>
#include <cassert>
#include "EntityManager.h"
#include "Event.h"
class SystemManager {
public:
    SystemManager(unsigned int numberSystems) {
        systems.resize(numberSystems);
    }
    
    SystemManager() {}
    ~SystemManager() {
    }

    void addSystem(std::unique_ptr<System> system) {
        systems.push_back(std::move(system));
    }
    
    std::unique_ptr<System>& operator[](unsigned int index) {
        return systems[index];
    }
    
    void addSystem(unsigned int position, std::unique_ptr<System> &&system) {
        systems[position] = std::move(system);
    }

    template <typename T> std::unique_ptr<T> getSystem(int index) {
        if(index >= systems.size())
            return nullptr;
        return std::dynamic_pointer_cast<T>(systems[index]);
    }

    void update(float dt, EntityManager& em, EventManager &event);
    void init(EntityManager& em, EventManager &event);
    //void call_back(Entity *e);

private:
    std::vector<std::unique_ptr<System> > systems;
};
