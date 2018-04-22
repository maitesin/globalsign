#pragma once

#include <iostream>

namespace globalsign {
    
class Treap {
    public:
    Treap();
    ~Treap();

    bool Has(char const * word) const;
    void Add(char const * word);
    void IncreasePriority(char const * word);
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
    };

    void BubbleUp(TreapNode * node);
    void SinkDown(TreapNode * node);
    TreapNode * Find(char const * word) const;
    void Add(TreapNode * node, char const * word, size_t priority);

    size_t size;
    TreapNode * root;
}; // class Heap

} // namespace globalsign
