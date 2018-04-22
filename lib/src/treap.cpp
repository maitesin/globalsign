#include "treap.hpp"

namespace globalsign {

Treap::Treap(): size(0), root(nullptr) {}
Treap::~Treap() {
    while(!IsEmpty()) {
        Pop();
    }
}

bool Treap::Has(char const * word) const {
    auto found = Find(word);
    return found != nullptr;
}

void Treap::Add(char const * word) {
    if (Has(word)) {
        throw std::invalid_argument("The word to be added is already present in the Treap");
    }
    size++;
    if (root == nullptr) {
        root = new TreapNode();
        root->value = word;
        root->priority = 1;
        root->parent = root->left = root->right = nullptr;
    } else {
        Add(root, word, 1);
    }
}

void Treap::IncreasePriority(char const * word) {}
char const * Treap::Top() const {}
void Treap::Pop() {
    if (!IsEmpty()) {
        delete root;
        size--;
    }
}

size_t Treap::Size() const {
    return size;
}

bool Treap::IsEmpty() const {
    return size == 0;
}

void Treap::BubbleUp(Treap::TreapNode * node) {}
void Treap::SinkDown(Treap::TreapNode * node) {}
Treap::TreapNode * Treap::Find(char const * word) const {
    return nullptr;
}

void Treap::Add(Treap::TreapNode * node, char const * word, size_t priority) {

}

} // namespace globalsign