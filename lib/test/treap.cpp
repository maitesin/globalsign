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

TEST_F(TreapTest, FiveWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, SixWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, SevenWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, EightWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    char const * word8 = "world";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.Add(word8);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word8, 8);
    EXPECT_EQ(word8, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, NineWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    char const * word8 = "world";
    char const * word9 = "Monkey";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.Add(word8);
    treap.Add(word9);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word8, 8);
    EXPECT_EQ(word8, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word9, 9);
    EXPECT_EQ(word9, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, TenWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    char const * word8 = "world";
    char const * word9 = "Monkey";
    char const * word10 = "Island";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.Add(word8);
    treap.Add(word9);
    treap.Add(word10);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word8, 8);
    EXPECT_EQ(word8, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word9, 9);
    EXPECT_EQ(word9, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word10, 10);
    EXPECT_EQ(word10, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, ElevenWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    char const * word8 = "world";
    char const * word9 = "Monkey";
    char const * word10 = "Island";
    char const * word11 = "magic";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.Add(word8);
    treap.Add(word9);
    treap.Add(word10);
    treap.Add(word11);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word8, 8);
    EXPECT_EQ(word8, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word9, 9);
    EXPECT_EQ(word9, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word10, 10);
    EXPECT_EQ(word10, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word11, 11);
    EXPECT_EQ(word11, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, TwelveWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    char const * word8 = "world";
    char const * word9 = "Monkey";
    char const * word10 = "Island";
    char const * word11 = "magic";
    char const * word12 = "the";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.Add(word8);
    treap.Add(word9);
    treap.Add(word10);
    treap.Add(word11);
    treap.Add(word12);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word8, 8);
    EXPECT_EQ(word8, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word9, 9);
    EXPECT_EQ(word9, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word10, 10);
    EXPECT_EQ(word10, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word11, 11);
    EXPECT_EQ(word11, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word12, 12);
    EXPECT_EQ(word12, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, ThirdteenWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    char const * word8 = "world";
    char const * word9 = "Monkey";
    char const * word10 = "Island";
    char const * word11 = "magic";
    char const * word12 = "the";
    char const * word13 = "gathering";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.Add(word8);
    treap.Add(word9);
    treap.Add(word10);
    treap.Add(word11);
    treap.Add(word12);
    treap.Add(word13);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word8, 8);
    EXPECT_EQ(word8, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word9, 9);
    EXPECT_EQ(word9, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word10, 10);
    EXPECT_EQ(word10, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word11, 11);
    EXPECT_EQ(word11, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word12, 12);
    EXPECT_EQ(word12, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word13, 13);
    EXPECT_EQ(word13, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, FourteenWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    char const * word8 = "world";
    char const * word9 = "Monkey";
    char const * word10 = "Island";
    char const * word11 = "magic";
    char const * word12 = "the";
    char const * word13 = "gathering";
    char const * word14 = "handball";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.Add(word8);
    treap.Add(word9);
    treap.Add(word10);
    treap.Add(word11);
    treap.Add(word12);
    treap.Add(word13);
    treap.Add(word14);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word8, 8);
    EXPECT_EQ(word8, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word9, 9);
    EXPECT_EQ(word9, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word10, 10);
    EXPECT_EQ(word10, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word11, 11);
    EXPECT_EQ(word11, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word12, 12);
    EXPECT_EQ(word12, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word13, 13);
    EXPECT_EQ(word13, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word14, 14);
    EXPECT_EQ(word14, treap.Top()) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, FiveteenWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    char const * word4 = "Vegetable";
    char const * word5 = "awesome";
    char const * word6 = "rock";
    char const * word7 = "another";
    char const * word8 = "world";
    char const * word9 = "Monkey";
    char const * word10 = "Island";
    char const * word11 = "magic";
    char const * word12 = "the";
    char const * word13 = "gathering";
    char const * word14 = "handball";
    char const * word15 = "rules";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.Add(word4);
    treap.Add(word5);
    treap.Add(word6);
    treap.Add(word7);
    treap.Add(word8);
    treap.Add(word9);
    treap.Add(word10);
    treap.Add(word11);
    treap.Add(word12);
    treap.Add(word13);
    treap.Add(word14);
    treap.Add(word15);
    treap.IncreasePriority(word1, 1);
    EXPECT_EQ(word1, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word2, 2);
    EXPECT_EQ(word2, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word3, 3);
    EXPECT_EQ(word3, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word4, 4);
    EXPECT_EQ(word4, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word5, 5);
    EXPECT_EQ(word5, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word6, 6);
    EXPECT_EQ(word6, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word7, 7);
    EXPECT_EQ(word7, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word8, 8);
    EXPECT_EQ(word8, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word9, 9);
    EXPECT_EQ(word9, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word10, 10);
    EXPECT_EQ(word10, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word11, 11);
    EXPECT_EQ(word11, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word12, 12);
    EXPECT_EQ(word12, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word13, 13);
    EXPECT_EQ(word13, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word14, 14);
    EXPECT_EQ(word14, treap.Top()) << "Top element in the Treap should be the one with highest priority";
    treap.IncreasePriority(word15, 15);
    EXPECT_EQ(word15, treap.Top()) << "Top element in the Treap should be the one with highest priority";
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