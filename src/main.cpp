#include <iostream>
#include "EntityManager.h"
#include "System.h"
#include "ComponentManager.h"
class Position : public Component<Position> {
    public:
        Position(int id):Component<Position>() {}
        int x;
        int y;
        ~Position() {}
};

class Data : public Component<Data> {
    public:
        Data(int id): Component() {}
        int x;
        int y;
        ~Data() {}
};

class Movement : public System{
    public:
        Movement() {}
        void update(float dt, ComponentManager &compo) {
         /*  for(std::shared_ptr<Component> c : compo.getComponents<Position>()) {
               std::shared_ptr<Position> p = std::dynamic_pointer_cast<Position>(c);
                if(p) {
                    p->x++;
                }
           }*/
        }
        void init() {}
};

int main() {
    EntityManager manager;
    ComponentManager compo;
    Entity e = manager.createEntity();
    Entity e2 = manager.createEntity();

    manager.destroyEntity(e2);
    //manager.refresh();

    e2 = manager.createEntity();


    std::cout << "Components "<< std::endl;
    std::shared_ptr<Position> p = std::make_shared<Position>(Position(e));
    std::shared_ptr<Position> p2 = std::make_shared<Position>(Position(e));
    std::shared_ptr<Data> d = std::make_shared<Data>(Data(e));
    p->x = 5;
    p->y = 6;


    std::cout << "test1 " << compo.addComponent<Position>(p)<<std::endl;
    //std::cout << "test2 " << compo.addComponent<Position>(p2)<<std::endl;
    //std::shared_ptr<Position> a = compo.getComponent<Position>(e);
    //std::cout << a->x << " " << a->y << std::endl; 
    /*Movement m;
    m.update(0, compo);
    a = compo.getComponent<Position>(e);
    std::cout << " " << a->x << " " << a->y << std::endl;*/


    return 0;
}
