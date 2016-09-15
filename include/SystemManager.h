#pragma once
#include "System.h"
#include <memory>
#include <typeinfo> 
class SystemManager {
	public:
		SystemManager() {}
		~SystemManager() {}

		template <typename T>
		bool addSystem(std::shared_ptr<System<T>> system) {
 				if(systems.find(T::id()) !=  systems.end()) return false;
              systems[T::id()] = system;
              return true;
		}

		template <typename T>
        std::shared_ptr<T> getSystem() {
            if(systems.find(T::id()) == systems.end()) return nullptr;
            return std::dynamic_pointer_cast<T>(systems[T::id()]);
        }
	private:
		std::unordered_map<std::string, std::shared_ptr<BaseSystem>> systems;

};
