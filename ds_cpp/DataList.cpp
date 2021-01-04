#include <iostream>
using namespace std;

template <typename T> class DataList;
template <typename T> class Node {
    friend class DataList<T>;
    private:
        T key;
    public:
        Node(const T &value): key(value) {}
        T GetKey() const {
            return key;
        }
        void SetKey(T k) {
            key = k;
        }
};

template <typename T> class DataList {
    protected:
        Node<T> *elements;
        int arraySize;
        int currentSize;
    public:
        DataList(int sz=10): arraySize(10) {
            elements = new Node<T>[sz];
            currentSize = 0;
        }
        virtual ~DataList() {
            delete [] elements;
        }
        int Length() const {
            return currentSize;
        }
        friend ostream &operator << (ostream &OutStream, const DataList<T> &OutList);
        friend istream &operator >> (istream &InStream, const DataList<T> &InList);
};
