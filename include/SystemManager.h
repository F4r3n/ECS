#pragma once
#include "System.h"
#include <memory>
#include <typeinfo>
#include <cassert>

class SystemManager
{
public:
    SystemManager()
    {
    }
    ~SystemManager()
    {
    }

    bool addSystem(std::shared_ptr<System> system)
    {
        systems.push_back(system);
    }

    template <typename T> std::shared_ptr<T> getSystem(int index)
    {
        if(index >= systems.size())
            return nullptr;
        return std::dynamic_pointer_cast<T>(systems[index]);
    }
    
    void update(float dt, EntityManager &em);
       

private:
    std::vector<std::shared_ptr<System> > systems;
};
