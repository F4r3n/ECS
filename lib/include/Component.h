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

        static std::string id() {
        	return typeid( T ).name();
        }


        virtual ~Component() {}
        friend class ComponentManager;
    private:
    	
};

#endif
