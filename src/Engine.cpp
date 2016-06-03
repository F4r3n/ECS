#include "Engine.h"

Engine::Engine() {}

Engine::~Engine() {}

void Engine::update(float dt, EntityManager &em) {
    for(System *s : systems) {
        s->update(dt, em);
    }
}
