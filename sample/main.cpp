#include <iostream>
#include "EntityManager.h"
#include "System.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include "Entity.h"
#include <chrono>
class Position : public Component<Position>
{
public:
    Position()
    {
    }
    int x;
    int y;
    ~Position()
    {
    }
};

class Data : public Component<Data>
{
public:
    Data()
    {
    }
    int x;
    int y;
    ~Data()
    {
    }
};

class Movement : public System
{
public:
    Movement()
    {
        addComponent<Position>();
    }
    void update(float dt, std::shared_ptr<Entity> e)
    {
        std::cout << e->ID << std::endl;
    }
    ~Movement()
    {
    }
    void init()
    {
    }
};

int main()
{
    ComponentManager compo;
    std::shared_ptr<Entity> e = EntityManager::get().createEntity();
    std::shared_ptr<Entity> e2 = EntityManager::get().createEntity();
    std::cout << e->ID << std::endl;
    std::cout << e2->ID << std::endl;
    //auto start = std::chrono::system_clock::now();
    //for(int i = 0; i < 10000; ++i) {
    //    EntityManager::get().createEntity();
    //}
    //auto end = std::chrono::system_clock::now();
    //auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    //std::cout << "Time " << elapsed.count() << '\n';
    e2->destroy();

    SystemManager systems;
    systems.addSystem(std::make_shared<Movement>());
    // manager.destroyEntity(e2);
    // manager.refresh();
    e2 = EntityManager::get().createEntity();
    //std::cout << e2->ID << std::endl;

    std::cout << "Components " << std::endl;
    std::shared_ptr<Position> p = std::make_shared<Position>(Position());
    std::shared_ptr<Position> p2 = std::make_shared<Position>(Position());

    std::shared_ptr<Data> d = std::make_shared<Data>(Data());
    p->x = 5;
    p->y = 6;
    // EntityManager::get().addComponent<Position>(e, p);
    e->addComponent<Position>(p);
    //e2->addComponent<Position>(p2);
    p = e->get<Position>();
    std::cout << p->x << " " << p->y << std::endl;
    systems.update(0.16, EntityManager::get());

    // std::cout << "test1 " << compo.addComponent<Position>(p)<<std::endl;
    // std::cout << "test2 " << compo.addComponent<Position>(p2)<<std::endl;
    // std::cout << "test3 " << compo.addComponent<Data>(d)<<std::endl;
    // std::shared_ptr<Position> a = compo.getComponent<Position>();

    /* std::shared_ptr<Movement> m = std::make_shared<Movement>();
     system.addSystem<Movement>(m);
     m->update(0, compo);
     a = compo.getComponent<Position>(e);
     std::cout << " " << a->x << " " << a->y << std::endl;*/

    return 0;
}

