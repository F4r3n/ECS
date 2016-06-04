#ifndef SYSTEM_H
#define SYSTEM_H

#include "ComponentManager.h"

class System {
    public:
        System();
        ~System();

        virtual void update(float dt, ComponentManager &em) = 0;
        virtual void init() = 0;

};

#endif
