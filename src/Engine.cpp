#include "Engine.h"

Engine::Engine() {}

Engine::~Engine() {}

void Engine::update(float dt, ComponentManager &em) {
    for(System *s : systems) {
        s->update(dt, em);
    }
}
