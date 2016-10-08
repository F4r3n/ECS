#include "ECS.h"
#include "gtest/gtest.h"
class ComponentTest : public ::testing::Test {
public:
    Entity* e1;
    Entity* e2;

    void SetUp() {
        e1 = EntityManager::get().createEntity();
        e2 = EntityManager::get().createEntity();
        EntityManager::get().make();
    }

    void TearDown() {
        e1->destroy();
        e2->destroy();
    }
};

class Data : public Component<Data> {
public:
    int a = 0;
};

class Data2 : public Component<Data2> {
public:
    int a = 0;
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