#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "Entity.h"
#include <array>

#define POOL_SIZE 10000
class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        Entity createEntity();
        void destroyEntity(size_t id);
        std::vector<Entity> getEntities();
        void refresh();
    private:
        static int ids;

        std::array<Entity, POOL_SIZE> entities;

        std::vector<size_t> free_id;

        std::vector<Entity> entities_alive;
        std::vector<Entity> entities_killed;

};


#endif
