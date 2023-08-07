#pragma once
#include <string>
#include <cstddef>
#include "Config.h"
#include <limits>

class ComponentManager;


class BaseComponent {
public:
	friend class ComponentManager;
    BaseComponent();
    const std::string& GetName() const {return _name;}
    virtual uint16_t GetType() const = 0;
    
protected:
	virtual ~BaseComponent();
    std::string _name = "";
    static uint16_t family_counter;
};


template <class T> class Component : public BaseComponent {

public:
    Component() {
    }

    static uint16_t GetID() {
        static uint16_t i = family_counter++;

        return i;
    }

    virtual uint16_t GetType() const
    {
        static uint16_t type = GetID();
        return type;
    }

protected:
	virtual ~Component() {}

private:

};


