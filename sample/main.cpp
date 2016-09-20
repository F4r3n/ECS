#include <iostream>
#include "EntityManager.h"
#include "System.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include "Entity.h"
#include <chrono>
class Position : public Component<Position> {
public:
    Position() {
    }
    int x;
    int y;
    ~Position() {
    }
};

class Data : public Component<Data> {
public:
    Data() {
    }
    int x;
    int y;
    ~Data() {
    }
};

class Movement : public System {
public:
    Movement() {
        addComponent<Position>();
    }
    void update(float dt, std::shared_ptr<Entity> e) {
        // std::cout << e->ID << std::endl;
    }
    void over() {
    }
    ~Movement() {
    }
    void init(std::shared_ptr<Entity> e) {
    }
};

int main() {
    ComponentManager compo;
    std::shared_ptr<Entity> e = EntityManager::get().createEntity();
    std::shared_ptr<Entity> e2 = EntityManager::get().createEntity();
    std::cout << e->ID << std::endl;
    std::cout << e2->ID << std::endl;

  

    std::cout << "Components " << std::endl;


    // EntityManager::get().addComponent<Position>(e, p);
    Position *p = e->addComponent<Position>();
    std::cout << p << std::endl;
    p->x = 5;
    p->y = 6;
    p = e->get<Position>();
    std::cout << p->x <<" " << p->y<< std::endl;
    return 0;
}
