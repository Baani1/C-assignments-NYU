/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions.
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>
#include <cassert>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c == 0) ? 1 : 0;
}

template <class T>
class RBTNode {
    RBTNode<T>* parent, * left, * right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
        color(RED),
        parent(nullptr),
        left(nullptr),
        right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1>*);
    template <class T1>
    friend int getColor(RBTNode<T1>*);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T>* node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T>* node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T>* root;
    void singleCCR(RBTNode<T>*& point);
    void doubleCR(RBTNode<T>*& point);
    void singleCR(RBTNode<T>*& point);
    void doubleCCR(RBTNode<T>*& point);

public:
    RBT() : root(nullptr) {}

    void insert(const T&);
    void insertFixup(RBTNode<T>*& node);
    void insert(const T&, RBTNode<T>*& point, RBTNode<T>* parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T>*& point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T>*& point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T>*& point) {
    if (point && point->left) {
        RBTNode<T>* grandparent = point;
        RBTNode<T>* parent = point->left;

        // Perform the rotation
        grandparent->left = parent->right;
        if (parent->right)
            parent->right->parent = grandparent;

        parent->right = grandparent;
        parent->parent = grandparent->parent;
        grandparent->parent = parent;

        point = parent;
    }
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T>*& point) {
    if (point && point->right) {
        RBTNode<T>* grandparent = point;
        RBTNode<T>* parent = point->right;

        // Perform the rotation
        grandparent->right = parent->left;
        if (parent->left)
            parent->left->parent = grandparent;

        parent->left = grandparent;
        parent->parent = grandparent->parent;
        grandparent->parent = parent;

        point = parent;
    }
}



template <class T>
void RBT<T>::insertFixup(RBTNode<T>*& node) {
    while (node->parent != nullptr && getColor(node->parent) == RED) {
        RBTNode<T>* parent = node->parent;
        RBTNode<T>* grandparent = parent->parent;

        if (parent == grandparent->left) {
            RBTNode<T>* uncle = grandparent->right;

            if (uncle && getColor(uncle) == RED) {
                // Case 1: Uncle is red
                swapColor(grandparent);
                swapColor(parent);
                swapColor(uncle);
                node = grandparent;
            }
            else {
                // Case 2: Uncle is black
                if (node == parent->right) {
                    // Case 2.1: Node is a right child
                    node = parent;
                    singleCCR(node);
                }

                // Case 2.2: Node is a left child or Case 2.1 finished
                swapColor(parent);
                swapColor(grandparent);
                singleCR(grandparent);
            }
        }
        else {
            // Symmetric cases for right subtree
            RBTNode<T>* uncle = grandparent->left;

            if (uncle && getColor(uncle) == RED) {
                // Symmetric Case 1: Uncle is red
                swapColor(grandparent);
                swapColor(parent);
                swapColor(uncle);
                node = grandparent;
            }
            else {
                // Symmetric Case 2: Uncle is black
                if (node == parent->left) {
                    // Symmetric Case 2.1: Node is a left child
                    node = parent;
                    singleCR(node);
                }

                // Symmetric Case 2.2: Node is a right child or Symmetric Case 2.1 finished
                swapColor(parent);
                swapColor(grandparent);
                singleCCR(grandparent);
            }
        }
    }
    root->color = BLACK; // Ensure the root is always black
}

template <class T>
void RBT<T>::insert(const T& toInsert, RBTNode<T>*& point, RBTNode<T>* parent) {
    if (point == nullptr) {
        point = new RBTNode<T>(toInsert);
        point->parent = parent;
        point->color = RED;

        RBTNode<T>* curr_node = point;
        insertFixup(curr_node);
    }
    else if (toInsert < point->data) {
        insert(toInsert, point->left, point);
    }
    else {
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insert(const T& toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */
    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
    cout << endl;
    cout << "---------------------" << endl;
    cout << endl;
    RBT<int> c;
    count = 5;
    for (int i = count; i > 0; i--) {
        c.insert(i);
    }
    c.prettyPrint();
    /* EXPECTED OUTPUT:
                    Data: 5
                    COLOR: BLACK
    Data: 4
    COLOR: BLACK
                                    Data: 3
                                    COLOR: RED
                    Data: 2
                    COLOR: BLACK
                                    Data: 1
                                    COLOR: RED
    */
    height = c.height();
    assert(height <= 2 * log2(count));
}