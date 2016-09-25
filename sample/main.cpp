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
    int x = 0;
    int y = 0;
    ~Position() {
    }
};

class Data : public Component<Data> {
public:
    Data() {
    }
    int x = 1;
    int y = 1;
    ~Data() {
    }
};

class C2 : public Component<C2> {
public:
    C2() {
    }
    int x = 2;
    int y = 2;
    ~C2() {
    }
};


class Movement : public System {
public:
    Movement() {
        addComponent<Position>();
    }
    void update(float dt, Entity* e) {
        //std::cout << "Called m" << std::endl;
        //std::cout << e->get<Position>()->x << std::endl;
    }
    void pre_update() {
               // std::cout << "Movement" << std::endl;

    }
    void over() {
    }
    ~Movement() {
    }
    void init(Entity* e) {
      //  std::cout << "Init movement" << std::endl;
      // Entity *en = EntityManager::get().createEntity();
      //  std::cout << en->ID << std::endl;
      //  en->addComponent<Position>();
        
    }
};

class ScriptSystem : public System {
public:
    ScriptSystem() {
        addComponent<Data>();
    }
    void update(float dt, Entity* e) {
        //std::cout << "Called s" << std::endl;
        //std::cout << e->get<Data>()->x << std::endl;
    }
    void pre_update() {
       // std::cout << "Script" << std::endl;
    }
    void over() {
    }
    ~ScriptSystem() {
    }
    void init(Entity* e) {
      // std::cout << "Init script" << std::endl;
      // Entity *en = EntityManager::get().createEntity();
      // std::cout << en->ID << std::endl;
      // en->addComponent<C2>();
        
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

    e->addComponent<Position>();
    e->addComponent<Data>();
    // p->x = 5;
    // p->y = 6;
    // p = e->get<Position>();
    // std::cout << p->x <<" " << p->y<< std::endl;
    EntityManager::get().make();
    std::shared_ptr<Movement> m = std::make_shared<Movement>();
    systemManager.addSystem(m);
    systemManager.addSystem(std::make_shared<ScriptSystem>());
    systemManager.init(EntityManager::get());
   // return -1;
   // return -1;
    while(1) {

        //if(i < 100) {
        //    Position* p = EntityManager::get().createEntity()->addComponent<Position>();
        //    p->x = i;
        //}
        systemManager.update(0.016, EntityManager::get());
        //++i;
    }
    return 0;
}
