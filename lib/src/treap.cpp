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
    if (root == nullptr) {
        root = new TreapNode(word, 1);
    } else {
        Add(root, word, 1);
    }
    size++;
}

void Treap::Add(Treap::TreapNode * node, char const * word, size_t priority) {
    if (std::strcmp(node->value, word) == -1) {
        if (node->left == nullptr) {
            node->left = new TreapNode(word, priority);
            node->left->parent = node;
            BubbleUp(node->left);
        } else {
            Add(node->left, word, priority);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new TreapNode(word, priority);
            node->right->parent = node;
            BubbleUp(node->right);
        } else {
            Add(node->right, word, priority);
        }
    }
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
    SinkDown(node);
    delete node;
    UpdateRoot();
}

size_t Treap::Size() const {
    return size;
}

bool Treap::IsEmpty() const {
    return size == 0;
}

void Treap::BubbleUp(Treap::TreapNode * node) {}
void Treap::SinkDown(Treap::TreapNode * node) {
    if (node != nullptr) {
        if (node->left != nullptr && node->right != nullptr) {
            if (node->left->priority < node->right->priority) {
                node->RotateLeft();
            } else {
                node->RotateRight();
            }
        }
        else if (node->left != nullptr) {
            node->RotateRight();
        } else if (node->right != nullptr) {
            node->RotateLeft();
        } else {
            return;
        }
    }
    SinkDown(node);
}

Treap::TreapNode * Treap::Find(Treap::TreapNode * node, char const * word) const {
    if (node == nullptr) return nullptr;
    if (std::strcmp(word, node->value) == 0) {
        return node;
    } else {
        return nullptr;
    }
}

void Treap::UpdateRoot() {
    while(root->parent != nullptr) {
        root = root->parent;
    }
}

} // namespace globalsign