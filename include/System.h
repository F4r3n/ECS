#ifndef SYSTEM_H
#define SYSTEM_H

#include "ComponentManager.h"
class SystemManager;
class BaseSystem {
	public:
		BaseSystem() {}
		virtual ~BaseSystem() {}
};



template <class T>
class System : public BaseSystem{

    public:
        System() {}
        virtual ~System() {}
        static std::string id() {
        	return typeid( T ).name();
        }

        virtual void update(float dt, ComponentManager &em) = 0;
        virtual void init() = 0;
        friend class SystemManager;

};

#endif
