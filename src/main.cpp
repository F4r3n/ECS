#include <iostream>
#include "EntityManager.h"
#include "System.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include "Entity.h"
class Position : public Component<Position> {
    public:
        Position() {}
        int x;
        int y;
        ~Position() {}
};

class Data : public Component<Data> {
    public:
        Data() {}
        int x;
        int y;
        ~Data() {}
};

class Movement : public System<Movement>{
    public:
        Movement() : System<Movement>(){}
        void update(float dt, ComponentManager &compo) {
           //for(std::shared_ptr<Component> c : compo.getComponents<Position>()) {
           //    std::shared_ptr<Position> p = std::dynamic_pointer_cast<Position>(c);
           //     if(p) {
           //         p->x++;
           //     }
           //}
        }
        ~Movement() {}
        void init() {}
};

int main() {
    ComponentManager compo;
    std::shared_ptr<Entity> e = EntityManager::get().createEntity();
    std::shared_ptr<Entity> e2 = EntityManager::get().createEntity();
    std::cout << e->ID << std::endl;
    std::cout << e2->ID << std::endl;

    SystemManager system;

    //manager.destroyEntity(e2);
    //manager.refresh();

    e2 = EntityManager::get().createEntity();


    std::cout << "Components "<< std::endl;
    std::shared_ptr<Position> p = std::make_shared<Position>(Position());
    std::shared_ptr<Position> p2 = std::make_shared<Position>(Position());
    std::shared_ptr<Data> d = std::make_shared<Data>(Data());
    p->x = 5;
    p->y = 6;
    
    //EntityManager::get().addComponent<Position>(e, p);
    e->addComponent<Position>(p);
    //std::cout << "test1 " << compo.addComponent<Position>(p)<<std::endl;
    //std::cout << "test2 " << compo.addComponent<Position>(p2)<<std::endl;
    //std::cout << "test3 " << compo.addComponent<Data>(d)<<std::endl;
    //std::shared_ptr<Position> a = compo.getComponent<Position>();
    //std::cout << a->x << " " << a->y << std::endl; 

   /* std::shared_ptr<Movement> m = std::make_shared<Movement>();
    system.addSystem<Movement>(m);
    m->update(0, compo);
    a = compo.getComponent<Position>(e);
    std::cout << " " << a->x << " " << a->y << std::endl;*/


    return 0;
}
