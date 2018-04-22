#include "treap.hpp"

namespace globalsign {

Treap::Treap(): size(0), root(nullptr) {}
Treap::~Treap() {}

bool Treap::Has(char const * word) const {}
void Treap::Add(char const * word) {}
void Treap::IncreasePriority(char const * word) {}
char const * Treap::Top() const {}
void Treap::Pop() {}
size_t Treap::Size() const {
    return size;
}
bool Treap::IsEmpty() const {}

void Treap::BubbleUp(std::unique_ptr<Treap::TreapNode> & node) {}
void Treap::SinkDown(std::unique_ptr<Treap::TreapNode> & node) {}
std::unique_ptr<Treap::TreapNode> & Treap::Find(char const * word) const {}
} // namespace globalsign