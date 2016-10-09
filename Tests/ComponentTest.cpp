#include "ECS.h"
#include "gtest/gtest.h"

class Data : public Component<Data> {
public:
    int a = 0;
};

class Data2 : public Component<Data2> {
public:
    int a = 0;
};
class ComponentTest : public ::testing::Test {
public:
    Entity* e1;
    Entity* e2;

    void SetUp() {
        e1 = EntityManager::get().createEntity();
        e2 = EntityManager::get().createEntity();

        for(int i = 0; i < 100; ++i) {
            EntityManager::get().createEntity();
        }

        EntityManager::get().make();
        EntityManager::get().getEntity(10)->addComponent<Data>();
        EntityManager::get().getEntity(20)->addComponent<Data>();
    }

    void TearDown() {
        e1->destroy();
        e2->destroy();
    }
};
TEST_F(ComponentTest, AddComponent) {
    Data* d = e1->addComponent<Data>();
    d->a = 1;

    ASSERT_EQ(e1->get<Data>()->a, 1);
    ASSERT_EQ(e1->get<Data2>(), nullptr);
}

TEST_F(ComponentTest, addMultipleCompo) {
    Data* d = e1->addComponent<Data>();
    d->a = 1;
    Data2* d2 = e1->addComponent<Data2>();
    d2->a = 0;

    ASSERT_EQ(e1->get<Data>()->a, 1);
    ASSERT_EQ(e1->get<Data2>()->a, 0);
}

TEST_F(ComponentTest, iterate) {
    int index = 0;

    for(auto e : EntityManager::get().iterate<Data>()) {
        index++;
    }
    ASSERT_EQ(index, 2);
}