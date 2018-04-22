#include <iostream>
#include <gtest/gtest.h>
#include "treap.hpp"

class TreapTest : public testing::Test {
    protected:
    virtual void TearDown() { while(!treap.IsEmpty()) {treap.Pop();} }
    globalsign::Treap treap;
}; // TreapTest class

TEST_F(TreapTest, Basic) {
    EXPECT_EQ(0, treap.Size()) << "Size for an empty Treap should be zero";
}

TEST_F(TreapTest, AddSingleWord) {
    char const * word = "Hello";
    treap.Add(word);
    EXPECT_EQ(1, treap.Size()) << "Size for an empty Treap should be zero";
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}