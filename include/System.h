#ifndef SYSTEM_H
#define SYSTEM_H

#include "EntityManager.h"

class System {
    public:
        System();
        ~System();

        virtual void update(float dt, EntityManager &em) = 0;
        virtual void init() = 0;

};

#endif
