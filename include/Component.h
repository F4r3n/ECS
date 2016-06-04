#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <memory>

class Component {
    public:
        Component();
        Component(int entityId);
        virtual ~Component();

        int entityId = -1;


};

#endif
