#include <iostream>

using namespace std;

template <typename T> class ThreadTree;
template <typename T> class ThreadNode;

template <typename T> class ThreadNode {
    friend class ThreadTree<T>;
    private:
        int ltag, rtag;
        ThreadNode <T> *leftChild, *rightChild;
        T data;
    public:
        ThreadNode(const T item): data(item), leftChild(nullptr), rightChild(nullptr), ltag(0), rtag(0) {}
};

template <typename T> class ThreadTree {
    protected:
        ThreadNode<T> *root;
        void CreateInThread(ThreadNode<T> *current, ThreadNode<T> *&pre);
        ThreadNode<T> *Parent(ThreadNode<T> *t);
    public: 
        ThreadTree(): root(nullptr) {};
        // find the first node using current as root
        ThreadNode<T> *First(ThreadNode<T> *current);
        // find the last node using current as root
        ThreadNode<T> *Last(ThreadNode<T> *current);
        // find the next node to current
        ThreadNode<T> *Next(ThreadNode<T> *current);
        // find the previous node to current
        ThreadNode<T> *Prior(ThreadNode<T> *current);
        void InOrder(void (*visit) (ThreadNode<T> *p));
        void PreOrder(void (*visit) (ThreadNode<T> *p));
        void PostOrder(void (*visit) (ThreadNode<T> *p));
};

template <typename T>
ThreadNode<T>* ThreadTree<T>::First(ThreadNode<T> *current) {
    ThreadNode<T> *p = current;
    while (p->ltag == 0) {
        p = p->leftChild;
    }
    return p;
}

template <typename T>
ThreadNode<T>* ThreadTree<T>::Next(ThreadNode<T> *current) {
    ThreadNode<T> *p = current->rightChild;
    if (current->rtag == 0) {
        return First(p);
    } return p;
}

template <typename T>
ThreadNode<T>* ThreadTree<T>::Last(ThreadNode<T> *current) {
    ThreadNode<T> *p = current;
    while (p->rtag == 0) {
        p = p->rightChild;
        return p;
    }
}

template <typename T>
ThreadNode<T>* ThreadTree<T>::Prior(ThreadNode<T> *current) {
    ThreadNode<T> *p = current->leftChild;
    if (current->ltag == 0) {
        return Last(p);
    } return p;
}

template <typename T>
void ThreadTree<T>::InOrder(void (*visit)(ThreadNode<T> *p)) {
    ThreadNode <T> *p;
    for (p = First(root); p != nullptr; p = Next(p)) {
        visit(p);
    }
}

template <typename T> void ThreadTree<T>::CreateInThread(ThreadNode<T> *current, ThreadNode<T> *&pre) {
    if (current == nullptr)
        return;
    CreateInThread(current->leftChild, pre);
    if (current->leftChild == nullptr) {
        current->leftChild = pre;
        current->ltag = 1;
    }
    if (pre != nullptr && pre->rightChild == nullptr) {
        pre->rightChild = current;
        pre->rtag = 1;
    }
    pre = current;
    CreateInThread(current->rightChild, pre);
}
