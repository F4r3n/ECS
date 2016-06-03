#include <iostream>
#include "EntityManager.h"
#include "System.h"
class Position : public Component {
    public:
        Position() {
           name = "yop"; 
        }
        int x;
        int y;
};

class Data : public Component {
    public:
        Data() {
           name = "yop2"; 
        }
        int x;
        int y;
};

class Movement : public System{
    public:
        Movement() {}
        void update(float dt, EntityManager &em) {
           for(Entity *e : em.getEntities()) {
               std::cout << em.getEntities().size() << std::endl;
               std::shared_ptr<Position> p = e->getComponent<Position>();
               std::cout << p << std::endl;
                if(p) {
                    std::cout << "++" << std::endl;
                    p->x++;
                }
           }
        }
        void init() {}
};

int main() {
    EntityManager manager;
    Entity *e = manager.createEntity();
    std::shared_ptr<Position> p = std::make_shared<Position>(Position());
    p->x = 5;
    p->y = 6;
    std::cout << p->name << std::endl;
    e->addComponent<Position>(p);
    e->addComponent<Data>(std::make_shared<Data>(Data()));
    std::shared_ptr<Position> a = e->getComponent<Position>();
    std::cout << a->name << " " << a->x << " " << a->y << std::endl;
    Movement m;
    m.update(0, manager);
    a = e->getComponent<Position>();
    std::cout << a->name << " " << a->x << " " << a->y << std::endl;


    return 0;
}
