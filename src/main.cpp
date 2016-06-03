#include <iostream>
#include "EntityManager.h"
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

int main() {
    EntityManager manager;
    Entity e = manager.createEntity();
    Position *p = new Position();
    p->x = 5;
    p->y = 6;
    std::cout << p->name << std::endl;
    e.addComponent<Position>(p);
    e.addComponent<Data>(new Data());
    p = e.getComponent<Position>();
    std::cout << p->name << " " << p->x << " " << p->y << std::endl;
    return 0;
}
