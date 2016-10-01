#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include <array>
#include "ComponentManager.h"
#include <limits>
#define POOL_SIZE 1000000

class Entity;
typedef std::unique_ptr<Entity> pEntity;

class EntityManager
{
public:
    EntityManager();
    static EntityManager& get();
    ~EntityManager();
    
    Entity* createEntity();
    void getEntities(std::function<void(Entity*)> func);
    void getEntitiesWithComponents(std::function<void(Entity*)> func, std::bitset<MAX_COMPONENTS>& bits);
    void refresh();
    inline bool isExists(size_t id);
   

    template <typename T> T* addComponent(size_t ID, Component<T> *c)
    {
        if(entitiesComponents[ID] != nullptr) {
            return entitiesComponents[ID]->addComponent<T>(c);
        } else {
            entitiesComponents[ID] = std::make_unique<ComponentManager>();
            return entitiesComponents[ID]->addComponent<T>(c);
        }
    }
    
    template <typename T> T* addComponent(Entity* e, Component<T> *c)
    {
       return addComponent<T>(getID(e), c);
    }

    std::array<std::unique_ptr<ComponentManager>, POOL_SIZE>& getEntitiesComponents()
    {
        return entitiesComponents;
    }

    template <typename T> T* get(Entity* e)
    {
        if(!entitiesComponents[getID(e)])
            return nullptr;
        return entitiesComponents[getID(e)]->getComponent<T>();
    }

    void deleteEntity(Entity* e);
    std::vector<size_t> getEntitiesAlive();
    bool hasComponents(Entity* e, std::vector<std::size_t>& compo);
    bool hasComponents(Entity* e, std::bitset<MAX_COMPONENTS>& bits);
    void make();
private:
    void destroyEntity(size_t id, bool isActive);

    size_t getID(Entity* e);

    std::array<pEntity, POOL_SIZE> entities;

    std::vector<size_t> free_id;

    std::vector<pEntity> entities_alive;
    std::vector<pEntity> temp_entities;
    std::vector<size_t> entities_killed;

    std::array<std::unique_ptr<ComponentManager>, POOL_SIZE> entitiesComponents;
    static EntityManager em;
};

#endif
