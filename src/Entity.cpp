#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int id):id(id) {}

int Entity::getId() {
    return id;
}

void Entity::addComponent(std::shared_ptr<Component> c) {
    components.push_back(c);
}

Entity::~Entity() {}
