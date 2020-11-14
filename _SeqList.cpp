#include <iostream>

const int defaultSize = 20;

template <typename T> class SeqList {
    private:
        T *list;
        int maxSize;
        int last;
        SeqList<T> resize(int newSize);
    public:
        SeqList(int maxSize = defaultSize);
        SeqList(SeqList<T> &L);
        ~SeqList() { delete []list; };
        int length() const { return last + 1; }
        int find(T &x) const;
        int isIn(T &x);
        int insert(T &x);
        int search(T &x) const;
        int remove (int i);
        int next(T &x);
        int prior(T &x);
        int isEmpty() { return last == -1; }
        int isFull() { return last == maxSize - 1; }
        T get(int i) { return i < 0 || i > last ? NULL : list[i]; }
};

template <typename T> SeqList<T>::SeqList(int size) {
    if (size > 0) {
        maxSize = size; last = -1;
        list = new T[maxSize];
        if (list == NULL) {
            std::cerr << "failed to allocate memory" << std::endl;
            exit(1);
        }
    }
}

template <typename T> SeqList<T>::SeqList(SeqList<T> &L) {
    maxSize = L.maxSize();
    last = L.length() - 1;
    list = new T[maxSize];
    if (list == NULL) {
        std::cerr << "failed to allocate memory" << std::endl;
    }
    for (int i = 1; i < last + 1; i++) {
        list[i - 1] = L.getData(i);
    }
}

template <typename T> SeqList<T> SeqList<T>::resize(int newSize) {
    if (newSize <= 0) {
        std::cerr << "incorrect size" << std::endl;
    }
    if (newSize != maxSize) {
        T *newArray = new T[newSize];
        if (newArray == NULL) {
            std::cerr << "failed to allocate memory" << std::endl;
            exit(1);
        }
        int n = last + 1;
        T *srcptr = list;
        T *destptr = newArray;
        while(n--) {
            *destptr++ = *srcptr++;
        }
        delete []list;
        list = newArray;
        maxSize = newSize;
    }
}

template <typename T> int SeqList<T>::search(T &x) const {
    for (int i = 0; i < last; i++) 
        if (list[i] == x) 
            return i;
    return -1;
}
