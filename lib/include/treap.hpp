#pragma once

#include<iostream>
#include<memory>

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
        std::unique_ptr<TreapNode> left, right;
        std::weak_ptr<TreapNode> parent;
    };

    void BubbleUp(std::unique_ptr<TreapNode> & node);
    void SinkDown(std::unique_ptr<TreapNode> & node);
    std::unique_ptr<TreapNode> & Find(char const * word) const;

    size_t size;
    std::unique_ptr<TreapNode> root;
}; // class Heap

} // namespace globalsign
