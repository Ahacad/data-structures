#include <iostream>

const int defaultSize = 20;

// linear array
template <typename T> class Array {
    private:
        T *elements;
        int arraySize;
        // initialize array
        void get_array();
    public:
        Array(int size = defaultSize);
        Array(const Array<T> &x);
        ~Array() {
            delete []elements;
        }
        Array<T> &operator = (const Array<T> &A);
        T & operator [](int i);
        T * operator *() const {
            return elements;
        }
        // get length of array
        int length() const {
            return arraySize;
        }
        void resize(int size);
};

template <typename T> void Array<T>::get_array() {
    elements = new T[arraySize];
    if (elements == 0) {
        std::cerr << "failed to allocate" << std::endl;
        arraySize = 0;
        return;
    }
}

template <typename T> Array<T>::Array(int size) {
    if (size <= 0) {
        std::cerr << "invalid array size" << std::endl;
    }
    arraySize = size;
    get_array();
}

template <typename T> Array<T>::Array(const Array<T> &x) {
    int n = x.arraySize;
    arraySize = x.arraySize;
    elements = new T[n];
    if (elements == 0) {
        std::cerr << "failed to allocate memory" << std::endl;
        arraySize = 0;
        return;
    }
    T *srcptr = x.elements;
    T *destptr = elements;
    while (n--) {
        *destptr++ = *srcptr++;
    }
}

int main() {
    Array<int> a(5);
    return 0;
}
