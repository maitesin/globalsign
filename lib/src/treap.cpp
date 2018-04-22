#include "treap.hpp"
#include <stdexcept>
#include <cstring>

namespace globalsign {

Treap::Treap(): size(0), root(nullptr) {}
Treap::~Treap() {
    while(!IsEmpty()) {
        Pop();
    }
}

bool Treap::Has(char const * word) const {
    auto found = Find(root, word);
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

void Treap::Add(Treap::TreapNode * node, char const * word, size_t priority) {

}

void Treap::IncreasePriority(char const * word, size_t count) {
    auto found = Find(root, word);
    if (found == nullptr) {
        throw std::invalid_argument("The word to increase the priority is no present in the Treap");
    }

}
char const * Treap::Top() const {
    if (IsEmpty()) {
        throw std::invalid_argument("The top of an empty Treap does not exist");
    }
    return root->value;
}

void Treap::Pop() {
    if (!IsEmpty()) {
        Pop(root);
        size--;
    }
}

void Treap::Pop(Treap::TreapNode * node) {
    delete node;
}

size_t Treap::Size() const {
    return size;
}

bool Treap::IsEmpty() const {
    return size == 0;
}

void Treap::BubbleUp(Treap::TreapNode * node) {}
void Treap::SinkDown(Treap::TreapNode * node) {}
Treap::TreapNode * Treap::Find(Treap::TreapNode * node, char const * word) const {
    if (node == nullptr) return nullptr;
    if (std::strcmp(word, node->value) == 0) {
        return node;
    } else {
        return nullptr;
    }
}

} // namespace globalsign