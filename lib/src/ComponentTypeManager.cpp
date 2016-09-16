#include "ComponentTypeManager.h"

std::unordered_map<const std::type_info*, ComponentType*> ComponentTypeManager::registered;