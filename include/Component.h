#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <memory>
#include <typeinfo>  //for 'typeid' to work
#include "BaseComponent.h"
class ComponentManager;

template <typename C>
class ComponentHandle {
 typedef C ComponentType;
};

template <class T>
class Component : public BaseComponent {

    public:
    	typedef ComponentHandle<T> Handle;
        Component() {}
        Component(int entityId) {
        	this->entityId = entityId;
        }

        static int id() {
        	return reinterpret_cast<int>(typeid( T ).name());
        }


        virtual ~Component() {}
        int entityId = -1;
        friend class ComponentManager;
    private:
    	
};

#endif
