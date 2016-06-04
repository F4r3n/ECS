#include <iostream>
#include "EntityManager.h"
#include "System.h"
#include "ComponentManager.h"
class Position : public Component {
    public:
        Position(int id):Component(id) {
        }
        int x;
        int y;
};

class Data : public Component {
    public:
        Data(){}
        Data(int id): Component(id) {
        }
        int x;
        int y;
};

class Movement : public System{
    public:
        Movement() {}
        void update(float dt, ComponentManager &compo) {
           for(std::shared_ptr<Component> c : compo.getComponents<Position>()) {
               std::shared_ptr<Position> p = std::dynamic_pointer_cast<Position>(c);
                if(p) {
                    p->x++;
                }
           }
        }
        void init() {}
};

int main() {
    EntityManager manager;
    ComponentManager compo;
    Entity *e = manager.createEntity();
    std::shared_ptr<Position> p = std::make_shared<Position>(Position(e->getId()));
    p->x = 5;
    p->y = 6;
    compo.addComponent<Position>(p);
    compo.addComponent<Position>(p);
    std::shared_ptr<Position> a = compo.getComponent<Position>(e->getId());
    Movement m;
    m.update(0, compo);
    a = compo.getComponent<Position>(e->getId());
    std::cout << " " << a->x << " " << a->y << std::endl;


    return 0;
}
