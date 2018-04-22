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
    EXPECT_EQ(1, treap.Size()) << "Size for a Treap with a single element should be one";
}

TEST_F(TreapTest, TopSingleWord) {
    char const * word = "Hello";
    treap.Add(word);
    EXPECT_EQ(word, treap.Top()) << "Top a Treap with a single element should return that element";
}

TEST_F(TreapTest, AddSingleWordAndIncreaseThePriority) {
    char const * word = "Hello";
    treap.Add(word);
    treap.IncreasePriority(word, 2);
    EXPECT_EQ(1, treap.Size()) << "Size for a Treap with a single element should be one";
}

TEST_F(TreapTest, FailToAddTwiceTheSameWord) {
    char const * word = "Hello";
    treap.Add(word);
    EXPECT_THROW(treap.Add(word), std::invalid_argument) << "Adding twice the same word should fail";
}

TEST_F(TreapTest, AddTwoWords) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    treap.Add(word1);
    treap.Add(word2);
    EXPECT_EQ(2, treap.Size()) << "Size for a Treap with two elements should be two";
}

TEST_F(TreapTest, TwoWordsIncreasePriorityOfOneAndCheckTop) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    treap.Add(word1);
    treap.Add(word2);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, TwoWordsIncreasePriorityOfBothAndCheckTop) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    treap.Add(word1);
    treap.Add(word2);
    treap.IncreasePriority(word1, 1);
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, ThreeWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, FourWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, FailToIncreasePriorityOfAWordThatIsNotPresent) {
    char const * word = "Hello";
    EXPECT_THROW(treap.IncreasePriority(word, 1), std::invalid_argument) << "Increase the priority of a word that is not present should fail";
}

TEST_F(TreapTest, FailToCallTopWhenEmpty) {
    EXPECT_THROW(treap.Top(), std::invalid_argument) << "Calling top in an empty Treap should fail";
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}