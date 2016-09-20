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
    void update(float dt, Entity* e) {
        std::cout << e->get<Position>()->x << std::endl;
    }
    void over() {
    }
    ~Movement() {
    }
    void init(Entity* e) {
    }
};

int main() {
    ComponentManager compo;
    SystemManager systemManager;
    Entity* e = EntityManager::get().createEntity();
    Entity* e2 = EntityManager::get().createEntity();
    std::cout << e->ID << std::endl;
    std::cout << e2->ID << std::endl;
    e2->destroy();
  

    std::cout << "Components " << std::endl;


    // EntityManager::get().addComponent<Position>(e, p);
    //Position *p = e->addComponent<Position>();
    //p->x = 5;
    //p->y = 6;
    //p = e->get<Position>();
    //std::cout << p->x <<" " << p->y<< std::endl;
    
    
    std::shared_ptr<Movement> m = std::make_shared<Movement>();
    systemManager.addSystem(m);
    systemManager.init(EntityManager::get());
    while(1) {
        systemManager.update(0.016, EntityManager::get());
    }
    return 0;
}
