#pragma once

#include <iostream>
#include <stdexcept>

namespace globalsign {
    
class Treap {
    public:
    Treap();
    ~Treap();

    bool Has(char const * word) const;
    void Add(char const * word);
    void IncreasePriority(char const * word, size_t count);
    char const * Top() const;
    void Pop();
    size_t Size() const;
    bool IsEmpty() const;

    private:
    struct TreapNode {
        char const * value;
        size_t priority;
        TreapNode * left, * right;
        TreapNode * parent;

        TreapNode(char const * word, size_t priority): value(word), priority(priority), left(nullptr), right(nullptr), parent(nullptr) {}
        
        void RotateRight() {
            if (left == nullptr) {
                std::invalid_argument("Imposible to rotate right if left is null");
            }
            // Parents
            left->parent = parent;
            parent = left;

            // Children
            auto old_left = left;
            left = left->right;
            old_left->right = this;
            if (left)
                left->parent = this;
        }

        void RotateLeft() {
            if (right == nullptr) {
                std::invalid_argument("Imposible to rotate left if right is null");
            }
            // Parents
            right->parent = parent;
            parent = right;

            // Children
            auto old_right = right;
            right = right->left;
            old_right->left = this;
            if (right)
                right->parent = this;
        }
    };

    void BubbleUp(TreapNode * node);
    void SinkDown(TreapNode * node);
    TreapNode * Find(TreapNode * node, char const * word) const;
    void Add(TreapNode * node, char const * word, size_t priority);
    void Pop(TreapNode * node);
    void UpdateRoot();

    size_t size;
    TreapNode * root;
}; // class Heap

} // namespace globalsign
