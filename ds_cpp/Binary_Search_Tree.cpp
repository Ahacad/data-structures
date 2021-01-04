#include <iostream>

template <typename T> class BST;
template <typename T> class Node {
    friend class BST<T>;
    private:
        T data;
        Node<T> *left;
        Node<T> *right;
};

template <typename T> class BST {
    private:
        ;
    public:
        bool Insert(const T &x, Node<T> *ptr);
        bool Remove(const T &x, Node<T> *ptr);
};


template <typename T> Node<T> *BST<T>::Search(T n) {
    Node<T> *node = root;
    while (node != nullptr && node->data != n) {
        if (n < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (node == nullptr) 
        return nullptr;
    if (node->data == n)
        return node;
}

template <typename T> Node<T> *BST<T>::RecurSearch(T x, Node<T> *ptr) {
    if (ptr == nullptr)
        return nullptr;
    if (x < ptr->data) {
        return RecurSearch(x, ptr->left);
    } else if (x > ptr->data) {
        return RecurSearch(x, ptr->right);
    } else {
        return ptr;
    }
}

template <typename T> bool BST<T>::Insert(const T &x, Node<T> *ptr) {
    if (ptr == nullptr) {
        ptr = new Node<T>(x);
        if (ptr == nullptr) {
            std::cerr << "failed to allocate memory" << "\n";
        }
        return true;
    }
    if (x < ptr->data) {
        Insert(x, ptr->left);
    } else if (x > ptr->data) {
        Insert(x, ptr->right);
    } else {
        return false;
    }
}

template <typename T> bool BST<T>::Remove(const T &x, Node<T> *ptr) {
    ;
}
