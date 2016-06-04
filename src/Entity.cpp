#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int id):id(id) {}

int Entity::getId() {
    return id;
}


Entity::~Entity() {}
