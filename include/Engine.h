#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include "System.h"
#include "EntityManager.h"
class Engine {
    Engine();
    ~Engine();
    void update(float dt, EntityManager &em);

private:
    std::vector<System*> systems;

};


#endif
