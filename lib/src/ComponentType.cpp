#include "ComponentType.h"

int ComponentType::nextID = 0;
ComponentType::ComponentType()
{
    id = nextID;
    nextID++;
}