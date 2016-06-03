#ifndef SYSTEM_H
#define SYSTEM_H

class System {
    public:
        System();
        ~System();

        virtual void update(float dt) = 0;
        virtual void init() = 0;

};

#endif
