#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include <array>
#include "ComponentManager.h"
#include <limits>
#define POOL_SIZE 1000000

class Entity;
typedef std::unique_ptr<Entity> pEntity;
typedef std::bitset<MAX_COMPONENTS> Mask;
class EntityManager {
public:
    EntityManager();
    static inline EntityManager& get() {
        return em;
    }
    ~EntityManager();

    Entity* createEntity();
    void getEntities(std::function<void(Entity*)> func);
    void getEntitiesWithComponents(std::function<void(Entity*)> func, Mask& bits);
    void killAll();
    bool isExists(size_t id) const;
    inline bool checkID(size_t ID) const {
        return ID == MAX_ID;
    }

    template <typename T> T* addComponent(size_t ID, Component<T>* c) {
        if(checkID(ID))
            return nullptr;
        if(entitiesComponents[ID] != nullptr) {
            return entitiesComponents[ID]->addComponent<T>(c);
        } else {
            entitiesComponents[ID] = std::make_unique<ComponentManager>();
            return entitiesComponents[ID]->addComponent<T>(c);
        }
    }

    template <typename T> T* addComponent(Entity* e, Component<T>* c) {
        return addComponent<T>(getID(e), c);
    }

    std::array<std::unique_ptr<ComponentManager>, POOL_SIZE>& getEntitiesComponents() {
        return entitiesComponents;
    }

    template <typename T> T* get(Entity* e) {
        if(!entitiesComponents[getID(e)])
            return nullptr;
        return entitiesComponents[getID(e)]->getComponent<T>();
    }

    void deleteEntity(Entity* e);
    std::vector<size_t> getEntitiesAlive();
    bool hasComponents(Entity* e, const std::vector<std::size_t>& compo) const;
    bool hasComponents(Entity* e, const Mask& bits) const;
    void make();
    bool hasComponents(size_t id, const Mask& bits) const;
    
    template <typename T>
    bool hasComponent(size_t id) {
        if(checkID(id)) return false;
        return entitiesComponents[id]->has<T>();
    }
    inline Entity* getEntity(size_t id) {
        if(checkID(id)) return nullptr;
        return entities_alive[id].get();
    }
class EntityIterator : public std::iterator<std::input_iterator_tag, size_t> {
    public:
        EntityIterator(const Mask& mask, const size_t capacity, const size_t index) {
            this->mask = mask;
            this->capacity = capacity;
            this->currentIndex = index;
            next();
        }
       
       Entity* operator*() {
           return EntityManager::get().getEntity(currentIndex);
       }
      
        EntityIterator operator++() {
            currentIndex++;
            next();
            return EntityIterator(mask, capacity, currentIndex);
        }
        
         EntityIterator begin(){
             return EntityIterator(mask, capacity, 0);
        }
        
         EntityIterator end() {
             return EntityIterator(mask, capacity, capacity);
        }
        
        bool operator!=(EntityIterator &i) {
            return i.currentIndex != currentIndex;
        }
        
        void next() {
            
            while(!valid() && currentIndex < capacity) {
                currentIndex++;
            }
        }
        
        inline bool valid() const{
            return EntityManager::get().isExists(currentIndex)
            && EntityManager::get().hasComponents(currentIndex, mask);
        }
        
       
   

    private:
        Mask mask;
        size_t currentIndex;
        size_t capacity;
    };
    
     template <typename T>
    Mask createMask() {
        Mask mask;
        mask.set(T::id());
        return mask;
    }
    
     template <typename C1, typename C2, typename ... Components>
    Mask createMask() {
        return createMask<C1>() | createMask<C2, Components...>();
    }
    
    template <typename ...Args>
    EntityIterator iterate() {
        EntityIterator iterator(createMask<Args...>(), posIndex, 0);
        return iterator;
    }
    
    EntityIterator iterate(const Mask &mask) {
        EntityIterator iterator(mask, posIndex, 0);
        return iterator;
    }

private:
    void destroyEntity(size_t id, bool isActive);

    size_t getID(Entity* e);
    const size_t MAX_ID = std::numeric_limits<size_t>::max();

    std::vector<size_t> free_id;

    std::vector<pEntity> entities_alive;
    std::vector<pEntity> temp_entities;
    std::vector<size_t> entities_killed;

    std::array<std::unique_ptr<ComponentManager>, POOL_SIZE> entitiesComponents;
    static EntityManager em;

    size_t capacity = 0;
    size_t posIndex = 0;
    
};

    

#endif
