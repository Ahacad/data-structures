template <typename T> class AVLTree;

template <typename T> class AVLNode {
    friend class AVLTree<T>;
    private:
        T data; 
        int balance;
};

template <typename T> class AVLTree {
};
