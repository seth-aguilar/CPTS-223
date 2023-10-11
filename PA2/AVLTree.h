#ifndef AVLTree_H
#define AVLTree_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
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
    int height() {
        return height(root);
    }

    void insert(const T& value) {
        root = insert(root, value);
    }

    bool contains(const T& value) const {
        return contains(root, value);
    }

    bool validate() const {
        return validate(root);
    }

private:
    AVLNode<T>* root;

    void clear(AVLNode<T>* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    int height(AVLNode<T>* node) const {
        return node ? node->height : -1;
    }

    AVLNode<T>* insert(AVLNode<T>* node, const T& value) {
        if (!node) {
            return new AVLNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        else {
            // Duplicate values not allowed
            return node;
        }

        // Update height of the current node
        node->height = 1 + std::max(height(node->left), height(node->right));

        // Get the balance factor to check if it became unbalanced
        int balance = getBalance(node);

        // If unbalanced, perform rotations
        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    bool contains(AVLNode<T>* node, const T& value) const {
        if (!node) {
            return false;
        }

        if (value < node->data) {
            return contains(node->left, value);
        }
        else if (value > node->data) {
            return contains(node->right, value);
        }
        else {
            return true;
        }
    }

    bool validate(AVLNode<T>* node) const {
        if (!node) {
            return true;
        }

        int balance = getBalance(node);
        if (balance > 1 || balance < -1) {
            return false;
        }

        return validate(node->left) && validate(node->right);
    }

    int getBalance(AVLNode<T>* node) const {
        return height(node->left) - height(node->right);
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* node) {
        AVLNode<T>* newRoot = node->right;
        AVLNode<T>* temp = newRoot->left;

        // Perform rotation
        newRoot->left = node;
        node->right = temp;

        // Update heights
        node->height = 1 + std::max(height(node->left), height(node->right));
        newRoot->height = 1 + std::max(height(newRoot->left), height(newRoot->right));

        return newRoot;
    }

    AVLNode<T>* rotateRight(AVLNode<T>* node) {
        AVLNode<T>* newRoot = node->left;
        AVLNode<T>* temp = newRoot->right;

        // Perform rotation
        newRoot->right = node;
        node->left = temp;

        // Update heights
        node->height = 1 + std::max(height(node->left), height(node->right));
        newRoot->height = 1 + std::max(height(newRoot->left), height(newRoot->right));

        return newRoot;
    }
};

#endif // AVLTree_H