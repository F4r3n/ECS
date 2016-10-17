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

class Data2 : public Component<Data2> {
public:
    Data2() {
    }
    int x = 1;
    int y = 1;
    ~Data2() {
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

struct Collision {
    Collision(int i) {
        pos = i;
    }
    int pos = 1;
};

struct Collision2 {
    Collision2(int i) {
        pos = i;
    }
    int pos = 1;
};


class Movement : public System {
public:
    Movement() {
    }
    void update(float dt, EntityManager &em, EventManager &event) {
        for(auto e : em.iterate<Position>()) {
          
        }
       // std::cout << "Called m" << std::endl;
        //std::cout << e->get<Position>()->x << std::endl;
    }
    void pre_update(EntityManager &em) {
               // std::cout << "Movement" << std::endl;

    }
    void over() {
    }
    ~Movement() {
    }
    void init( EntityManager &em, EventManager &event) {
      //  std::cout << "Init movement" << std::endl;
      // Entity *en = EntityManager::get().createEntity();
      //  std::cout << en->ID << std::endl;
      //  en->addComponent<Position>();
        
    }
};

class ScriptSystem : public System, public Receiver<ScriptSystem>{
public:
    ScriptSystem() {
        addComponent<Data>();
    }
    void update(float dt, EntityManager &em, EventManager &event) {
       for(auto e : em.iterate<Data>()) {
          
        }
    }
    void pre_update( EntityManager &em) {
       // std::cout << "Script" << std::endl;
    }
    void over() {
    }
    ~ScriptSystem() {
    }
    
    void receive(const Collision &collision) {
        //std::cout << collision.pos << std::endl;
    }
    
     void receive(const Collision2 &collision) {
        //std::cout <<" 2 "<< collision.pos << std::endl;
    }
    
    void init( EntityManager &em, EventManager &event) {
       
      // std::cout << "Init script" << std::endl;
      // Entity *en = EntityManager::get().createEntity();
      // std::cout << en->ID << std::endl;
      // en->addComponent<C2>();
        
    }
};

int main() {
    
    SystemManager systemManager;
    for(int i = 0; i < 1000; ++i) {
        Entity* e = EntityManager::get().createEntity();
        e->addComponent<Position>();
        e->addComponent<Data>();
    }
    
    EntityManager::get().make();
    std::shared_ptr<Movement> m = std::make_shared<Movement>();
    systemManager.addSystem(m);
    systemManager.addSystem(std::make_shared<ScriptSystem>());
    systemManager.init(EntityManager::get(), EventManager::get());
  
  //Test 1000 iterations
    for(int i = 0; i < 1000; ++i){
        std::cout << "Itreation " << i << std::endl;
        //if(i < 100) {
        //    Position* p = EntityManager::get().createEntity()->addComponent<Position>();
        //    p->x = i;
        //}
        systemManager.update(0.016, EntityManager::get(), EventManager::get());
        //++i;
    }
    return 0;
}
