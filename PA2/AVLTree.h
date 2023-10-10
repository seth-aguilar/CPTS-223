#ifndef AVLTree_H
#define AVLTree_H

#include <iostream>
#include <algorithm>
#include "AVLNode.h"

template <typename T>
class AVLTree {
public:
    // Constructors
    AVLTree() : root(nullptr) {}

    // Destructor
    ~AVLTree() {
        clear(root);
    }

    // Member functions
    int height();
    void insert(const T& value);
    bool contains(const T& value) const;
    bool validate() const;

private:
    AVLNode<T>* root;

    void clear(AVLNode<T>* node);
    int height(AVLNode<T>* node) const;
    AVLNode<T>* insert(AVLNode<T>* node, const T& value);
    bool contains(AVLNode<T>* node, const T& value) const;
    bool validate(AVLNode<T>* node) const;
    int getBalance(AVLNode<T>* node) const;
    AVLNode<T>* rotateLeft(AVLNode<T>* node);
    AVLNode<T>* rotateRight(AVLNode<T>* node);
};

#endif // AVLTree_H