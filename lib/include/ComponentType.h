#pragma once

class ComponentType {
  public:
    ComponentType() {
        id = nextID;
        nextID++;
    }
    static int nextID;
    int id;
    
};