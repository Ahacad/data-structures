template <typename T> class AVLTree;
template <typename T> class AVLNode {
    friend class AVLTree<T>;
    protected:
        AVLNode<T> *left, *right;
        int balance;
        T data;
    public:
        AVLNode(): left(nullptr), right(nullptr), balance(0) {}
        AVLNode(T d, AVLNode<T> *l=nullptr, AVLNode<T> *r=nullptr): data(d), left(l), right(r), balance(0) {}
};
template <typename T> class AVLTree {
    public:
};

// unit test
