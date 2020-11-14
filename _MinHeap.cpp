#include <iostream>
#define defaultSize 10

template <typename T>
class MinHeap: public MinPQ<T> {
    private:
        T *heap;
        int currentSize;
        int maxHeapSize;
        void siftDown(int start, int m);
        void siftUp(int start);
    public: 
        MinHeap(int size);
        MinHeap(T arr[], int n);
        MinHeap(const MinHeap &R);
        ~MinHeap() {
            delete []heap;
        }
        bool isEmpty() const {
            return (currentSize == 0) ? true : false;
        }
        bool isFull() const {
            return (currentSize == maxHeapSize) ? true : false;
        }
        void makeEmpty() {
            currentSize = 0;
        }
        bool insert(const T &x);
        bool remove(T &x);
}

template <typename T> MinHeap<T>::MinHeap(int size) {
    maxHeapSize = (defaultSize < size) ? size : defaultSize;
    heap = new T [maxHeapSize];
    if (heap == NULL) {
        std::cerr << "" << std::endl;
        exit(1);
    }
    currentSize = 0;
}

template <typename T> MinHeap<T>::MinHeap(T arr[], int n) {
    maxHeapSize = (defaultSize < n) ? n : defaultSize;
    heap = new T [maxHeapSize];
    if (heap == NULL) {
        std::cerr << "" << std::endl;
        exit(1);
    }
    for (int i = 0; i < n; i++){
        heap[i] = arr[i];
    }
    currentSize = n;
    int currentPos = (currentSize - 2) / 2;
    while (currentPos >= 0) {
        siftDown(currentPos, currentSize - 1);
        currentPos--;
    }
}

template <typename T> void MinHeap<T>::siftDown(int start, int size) {
    int i = start, j = 2 * i + 1;
    T tmp = heap[i];
    while (j <= size) {
        if (j < size && heap[j] > heap[j + 1]) {
            j++;
        }
        if (tmp <= heap[j]) {
            break;
        } else {
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;
        }
        heap[i] = tmp;
    }
}

template <typename T> bool MinHeap<T>::insert(const Type &x) {
    if (currentSize == maxHeapSize) {
        std::cerr << "full" << std::endl;
        return false;
    }
    heap[currentSize] = x;
    siftUp(currentSize);
    currentSize++;
    return true;
}

template <typename T> void MinHeap<T>::siftUp(int start) {
    int j = start, i = (j - 1) / 2;
    T tmp = heap[j];
    while (j > 0) {
        if (heap[i] <= tmp) {
            break;
        } else {
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;
        }
    }
    heap[j] = tmp;
}

template <typename T> bool MinHeap<T>::remove(T &x) {
    if (!currentSize) {
        std::cerr << "empty heap" << std::endl;
        return false;
    }
    x = heap[0];
    heap[0] = heap[currentSize-1];
    currentSize--;
    siftDown(0, currentSize - 1);
    return true;
}


