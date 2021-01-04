#include <iostream>

template <typename T> class DataList;
template <typename T> class Node {
    friend class DataList<T>;
    private:
        T key;
    public:
        Node(const T &value): key(value) {}
        T GetKey() const { return key; }
        void SetKey(T k){ key = k; }
};


template <typename T> class DataList { 
    protected:
        Node<T> *elements;
        int arraySize = 5;
        int currentSize;
    public:
        DataList(int size=10): arraySize(size) {
            elements = new Node<T>[size];
            currentSize = 0;
        }
        virtual ~DataList() { delete []elements; }
        int Length() { return currentSize; }
};

template <typename T> class SearchList : public DataList<T> {
    public:
        SearchList(int size=10): DataList<T> (size) {}
        virtual ~SearchList() {}
        virtual int Search(const T &x) const;
};

template <typename T> class SortedList: public DataList<T> {
    public:
        SortedList(int size=10) {
            std::cout << this->arraySize;
        }
        ~SortedList() {}
        int BinarySearch(const T &x) const;
};

 //recursive binary search
/*
 *template <typename T> int SearchList<T>::BinarySearch(const T &x, const int low, const int high) const {
 *    if (low > high)
 *        return -1;
 *    int mid = (low + high) / 2;
 *    if (elements[mid].key < x) {
 *        mid = BinarySearch(x, mid + 1, high);
 *    } else if (elements[mid].key > x) {
 *        mid = BinarySearch(x, low, mid - 1);
 *    }
 *    return mid;
 *}
 */

// iterative binary search
template <typename T> int SortedList<T>::BinarySearch(const T &x) const {
    int high = currentSize - 1, low = 0, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (elements[mid].key < x) {
            low = mid + 1;
        } else if (elements[mid].key > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
