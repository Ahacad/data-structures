template <typename T> class Tree;
template <typename T> class TreeNode {
    friend class Tree<T>;
    private:
        T data;
        TreeNode<T> *firstChild, *nextSibling;
    public:
        TreeNode(T value, TreeNode<T> *fc=nullptr, TreeNode<T> *ns=nullptr):
            data(value), firstChild(fc), nextSibling(ns) {}
};

template <typename T> class Tree {
    private:
        TreeNode<T> *root, *current;
        bool find(TreeNode<T> *p, T value);
        void remove_subtree(TreeNode<T> *p);
        int find_parent(TreeNode<T> *t, TreeNode<T> *p);
    public:
        Tree() {
            root = current = nullptr;
        }
        bool getroot();
        bool isempty();
        bool first_child();
        bool next_sibling();
        bool parent();
        bool find(T target);
};
