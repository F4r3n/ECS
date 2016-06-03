#include "Engine.h"

Engine::Engine() {}

Engine::~Engine() {}

void Engine::update(float dt) {
    for(System *s : systems) {
        s->update(dt);
    }
}
