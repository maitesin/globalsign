#include <iostream>
#include <cstring>
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
    EXPECT_TRUE(std::strcmp(word, treap.Top().second) == 0) << "Top a Treap with a single element should return that element";
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

TEST_F(TreapTest, HasMethod) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * no_found = "Another";
    treap.Add(word1);
    treap.Add(word2);
    EXPECT_TRUE(treap.Has(word1)) << "Added word should be marked as present";
    EXPECT_TRUE(treap.Has(word2)) << "Added word should be marked as present";
    EXPECT_FALSE(treap.Has(no_found)) << "Non added word should never be marked as present";
}

TEST_F(TreapTest, TwoWordsIncreasePriorityOfOneAndCheckTop) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    treap.Add(word1);
    treap.Add(word2);
    treap.IncreasePriority(word1, 1);
    EXPECT_TRUE(std::strcmp(word1, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, TwoWordsIncreasePriorityOfBothAndCheckTop) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    treap.Add(word1);
    treap.Add(word2);
    treap.IncreasePriority(word1, 1);
    treap.IncreasePriority(word2, 2);
    EXPECT_TRUE(std::strcmp(word2, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, ThreeWordIncreasePriority) {
    char const * word1 = "Hello";
    char const * word2 = "Wololo";
    char const * word3 = "Animal";
    treap.Add(word1);
    treap.Add(word2);
    treap.Add(word3);
    treap.IncreasePriority(word1, 1);
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    EXPECT_TRUE(std::strcmp(word3, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    EXPECT_TRUE(std::strcmp(word4, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    EXPECT_TRUE(std::strcmp(word5, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    EXPECT_TRUE(std::strcmp(word6, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    EXPECT_TRUE(std::strcmp(word7, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    treap.IncreasePriority(word8, 8);
    EXPECT_TRUE(std::strcmp(word8, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    treap.IncreasePriority(word8, 8);
    treap.IncreasePriority(word9, 9);
    EXPECT_TRUE(std::strcmp(word9, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    treap.IncreasePriority(word8, 8);
    treap.IncreasePriority(word9, 9);
    treap.IncreasePriority(word10, 10);
    EXPECT_TRUE(std::strcmp(word10, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    treap.IncreasePriority(word8, 8);
    treap.IncreasePriority(word9, 9);
    treap.IncreasePriority(word10, 10);
    treap.IncreasePriority(word11, 11);
    EXPECT_TRUE(std::strcmp(word11, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    treap.IncreasePriority(word8, 8);
    treap.IncreasePriority(word9, 9);
    treap.IncreasePriority(word10, 10);
    treap.IncreasePriority(word11, 11);
    treap.IncreasePriority(word12, 12);
    EXPECT_TRUE(std::strcmp(word12, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    treap.IncreasePriority(word8, 8);
    treap.IncreasePriority(word9, 9);
    treap.IncreasePriority(word10, 10);
    treap.IncreasePriority(word11, 11);
    treap.IncreasePriority(word12, 12);
    treap.IncreasePriority(word13, 13);
    EXPECT_TRUE(std::strcmp(word13, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    treap.IncreasePriority(word8, 8);
    treap.IncreasePriority(word9, 9);
    treap.IncreasePriority(word10, 10);
    treap.IncreasePriority(word11, 11);
    treap.IncreasePriority(word12, 12);
    treap.IncreasePriority(word13, 13);
    treap.IncreasePriority(word14, 14);
    EXPECT_TRUE(std::strcmp(word14, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
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
    treap.IncreasePriority(word2, 2);
    treap.IncreasePriority(word3, 3);
    treap.IncreasePriority(word4, 4);
    treap.IncreasePriority(word5, 5);
    treap.IncreasePriority(word6, 6);
    treap.IncreasePriority(word7, 7);
    treap.IncreasePriority(word8, 8);
    treap.IncreasePriority(word9, 9);
    treap.IncreasePriority(word10, 10);
    treap.IncreasePriority(word11, 11);
    treap.IncreasePriority(word12, 12);
    treap.IncreasePriority(word13, 13);
    treap.IncreasePriority(word14, 14);
    treap.IncreasePriority(word15, 15);
    EXPECT_TRUE(std::strcmp(word15, treap.Top().second) == 0) << "Top element in the Treap should be the one with highest priority";
}

TEST_F(TreapTest, FailToIncreasePriorityOfAWordThatIsNotPresent) {
    char const * word = "Hello";
    EXPECT_THROW(treap.IncreasePriority(word, 1), std::invalid_argument) << "Increase the priority of a word that is not present should fail";
}

TEST_F(TreapTest, FailToCallTopWhenEmpty) {
    EXPECT_THROW(treap.Top().second, std::invalid_argument) << "Calling top in an empty Treap should fail";
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}