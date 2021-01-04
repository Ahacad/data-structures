template <typename T> class BST;
template <typename T> class BSTNode {
    friend class BST<T>;
    protected:
        T data;
        BSTNode<T> *left, *right;
    public: 
        virtual ~BSTNode() {}
        BSTNode(): left(nullptr), right(nullptr) {}
        BSTNode(const T d, BSTNode<T> *l=nullptr, BSTNode<T> *r=nullptr): data(d), left(l), right(r){}
        bool SetData(T d) {
            data = d;
            return 0;
        }
        T GetData() const {
            return data;
        }
};

