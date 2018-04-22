#pragma once

#include <iostream>

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
    };

    void BubbleUp(TreapNode * node);
    void SinkDown(TreapNode * node);
    TreapNode * Find(TreapNode * node, char const * word) const;
    void Add(TreapNode * node, char const * word, size_t priority);
    void Pop(TreapNode * node);

    size_t size;
    TreapNode * root;
}; // class Heap

} // namespace globalsign
