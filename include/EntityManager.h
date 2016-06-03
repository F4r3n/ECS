#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "Entity.h"
class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        Entity& createEntity();
    private:
        static int ids;

        std::vector<Entity> entities;

};


#endif
