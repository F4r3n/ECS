#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include <array>
#include "ComponentManager.h"

#define POOL_SIZE 10000

class Entity;
typedef std::shared_ptr<Entity> pEntity;
class EntityManager
{
public:
    EntityManager();
    ~EntityManager();
    pEntity createEntity();
    void destroyEntity(size_t id);
    std::vector<pEntity> getEntities();
    void refresh();
    inline bool isExists(size_t id);
    static EntityManager& get();

    template <typename T> void addComponent(size_t ID, std::shared_ptr<Component<T> > c)
    {
        if(entitiesComponents[ID] != nullptr) {
            entitiesComponents[ID]->addComponent<T>(c);
        } else {
            entitiesComponents[ID] = std::make_shared<ComponentManager>();
            entitiesComponents[ID]->addComponent<T>(c);
        }
    }
    template <typename T> void addComponent(Entity* e, std::shared_ptr<Component<T> > c)
    {
        addComponent<T>(getID(e), c);
    }

    std::array<std::shared_ptr<ComponentManager>, POOL_SIZE>& getEntitiesComponents()
    {
        return entitiesComponents;
    }

    template <typename T> std::shared_ptr<T> get(Entity* e)
    {
        if(!entitiesComponents[getID(e)])
            return nullptr;
        return entitiesComponents[getID(e)]->getComponent<T>();
    }

    void deleteEntity(Entity* e);
    std::vector<size_t> getEntitiesAlive();
    bool hasComponent(std::shared_ptr<Entity> e, std::vector<std::string> &compo);

private:
    size_t getID(Entity* e);
    static int ids;

    std::array<pEntity, POOL_SIZE> entities;

    std::vector<size_t> free_id;

    std::vector<pEntity> entities_alive;
    std::vector<size_t> entities_killed;

    std::array<std::shared_ptr<ComponentManager>, POOL_SIZE> entitiesComponents;
    static EntityManager em;
};

#endif
