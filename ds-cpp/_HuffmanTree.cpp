#include <iostream>
const int defaultSize = 20;
template <typename T> class HuffmanTree;
template <typename T> class HuffmanNode;

template <typename T> class HuffmanNode {
    friend class HuffmanTree;
    private:
        T data;
        HuffmanNode <T> *leftChild, *rightChild, *parent;
    public:
        HuffmanNode(T elem, 
                    HuffmanNode<T> *left=NULL, 
                    HuffmanNode<T> *right=NULL,
                    HuffmanNode<T> *pr=NULL):
            data(elem), leftChild(left), rightChild(right), parent(pr) {}
};

template <typename T> class HuffmanTree {
    public: 
        HuffmanTree(T w[], int n);
        ~HuffmanTree() { delete Tree(root); }
    protected:
        HuffmanNode<T> *root;
        void deleteTree(HuffmanNode<T> *t);
        void mergeTree(HuffmanNode<T> &ht1,
                       HuffmanNode<T> &ht2,
                       HuffmanNode<T> *&parent);
};

template <typename T> HuffmanTree<T>::HuffmanTree(T w[], int n) {
    HuffmanNode<T> *parent, &first, &second;
    HuffmanNode<T> *NodeList = new HuffmanNode<T>[n];
    MinHeap<T> hp;
    for (int i = 0; i < n; i++){
        NodeList[i].data = w[i + 1];
        NodeList[i].leftChild = NULL;
        NodeList[i].rightChild = NULL;
        NodeList[i].parent = NULL;
        hp.insert(NodeList[i]);
    }
}
