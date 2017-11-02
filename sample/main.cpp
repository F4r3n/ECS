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
        _name = "Position";
    }
    int x = 0;
    int y = 0;
    ~Position() {
    }
};



class Data : public Component<Data> {
public:
    Data() {
        _name = "Data";
    }
    int x = 1;
    int y = 1;
    ~Data() {
    }
};

class Data2 : public Component<Data2> {
public:
    Data2() {
        _name = "Data2";
    }
    int x = 1;
    int y = 1;
    ~Data2() {
    }
};

class C2 : public Component<C2> {
public:
    C2() {
        _name = "C2";
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


class Movement : public System<Movement> {
public:
    Movement() {
    }
    void update(float dt, EntityManager &em, EventManager &event) {
        for(auto e : em.iterate<Position>()) {
           std::cout << e->ID << std::endl;
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

class ScriptSystem : public System<ScriptSystem>, public Receiver<ScriptSystem>{
public:
    ScriptSystem() {
        
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
    
    SystemManager systemManager(0);

    Entity* e = EntityManager::get().createEntity();
    e->addComponent<Position>()->x = 1;
    e->addComponent<Data>();
    std::vector<BaseComponent*> compos = e->getAllComponents();
    for(auto c : compos) {
        std::cout << c->getName() << std::endl;
        if(c->getName().compare("Position") == 0) {
            Position* p = dynamic_cast<Position*>(c);
            if(p != nullptr) {
                std::cout << p->x << std::endl;
                p->x++;
            }
        }
    }
    std::cout << e->get<Position>()->x << std::endl;
    
    EntityManager::get().make();
    systemManager.addSystem<Movement>(new Movement());
   
    Movement * m = systemManager.getSystem<Movement>();
    systemManager.init(EntityManager::get(), EventManager::get());
    

  //Test 1000 iterations
    /*for(int i = 0; i < 1000; ++i){
        std::cout << "Itreation " << i << std::endl;
        //if(i < 100) {
        //    Position* p = EntityManager::get().createEntity()->addComponent<Position>();
        //    p->x = i;
        //}
        systemManager.update(0.016, EntityManager::get(), EventManager::get());
        //++i;
    }*/
    return 0;
}
