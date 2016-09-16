#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include "System.h"
#include "ComponentManager.h"
class Engine {
    Engine();
    ~Engine();
    void update(float dt, ComponentManager &em);

private:
    //std::vector<System*> systems;

};


#endif
