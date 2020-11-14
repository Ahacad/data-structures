#include <iostream>

template <typename T> class CircList;
template <typename T> class CircLinkNode {
    friend class CircList<T>;
    private:
        T data;
        CircLinkNode<T> *link;
    public:
        CircLinkNode(T d=0, CircLinkNode<T> *next=NULL): data(d), link(next) {}
};

template <typename T> class CircList {
    private:
        CircLinkNode<T> *first, *last, *current;
    public:
        CircList(const T &value);
        CircList(CircList<T> &L);
        ~CircList();
        int length() const;
        CircLinkNode<T> *getHead() const;
        void setHeader(CircLinkNode<T> *p) {
            first = p;
        }
        CircLinkNode<T> *search(T value);
        CircLinkNode<T> *locate(int i);
        T *getData(int i);
        void setData(int i, T &x);
        bool insert(int i, T &x);
        bool remove(int i, T &x);
        bool isEmpty() const {
            return first->link == first ? true : false;
        }
        void sort();
        void input();
        void output();
        CircList<T> operator = (CircList<T> &L);
};


