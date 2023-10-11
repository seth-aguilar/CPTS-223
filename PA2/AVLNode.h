#ifndef AVLNODE_H
#define AVLNODE_H

// Class template for AVLNode
template <typename T>
class AVLNode {
public:
    // Constructors
    AVLNode() : data(T()), left(nullptr), right(nullptr), height(0) {}
    explicit AVLNode(const T& value) : data(value), left(nullptr), right(nullptr), height(0) {}

    // Destructor
    ~AVLNode() {
        delete left;
        delete right;
    }

    // Data members
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;
};

#endif // AVLNODE_H