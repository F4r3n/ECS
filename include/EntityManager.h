#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include <array>
#include "ComponentManager.h"

#define POOL_SIZE 10000

class Entity;
class EntityManager
{
public:
    EntityManager();
    ~EntityManager();
    std::shared_ptr<Entity> createEntity();
    void destroyEntity(size_t id);
    std::vector<std::shared_ptr<Entity> > getEntities();
    void refresh();
    inline bool isExists(size_t id);
    static EntityManager& get();
    
    //template <typename T>
    //void addComponent(std::shared_ptr<Entity> e, std::shared_ptr<Component<T>> c);
    std::array<std::shared_ptr<ComponentManager>, POOL_SIZE>& getEntitiesComponents() {
        return entitiesComponents;
    }

private:
    static int ids;

    std::array<std::shared_ptr<Entity>, POOL_SIZE> entities;

    std::vector<size_t> free_id;

    std::vector<std::shared_ptr<Entity> > entities_alive;
    std::vector<size_t> entities_killed;

    std::array<std::shared_ptr<ComponentManager>, POOL_SIZE> entitiesComponents;
    static EntityManager em;
};

#endif
