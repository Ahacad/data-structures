const int N = 100;
template<typename T> int merge(T a[], int l, int m, int r) {
    int i, j;
    static T aux[N];
    for (i = m + 1; i > l; i--) 
        aux[i-1] = a[i-1];
    for (j = m; j < r; j++) 
        aux[r+m-j] = a[j+1];
    for (int k = l; k <= r; k++) {
        if (aux[j] < aux[i]) {
            a[k] = aux[j--];
        } else {
            a[k] = aux[i++];
        }
    }
    return 0;
}

template <typename T> int MergeSort(T a[], int l, int r) {
    if (r <= l)
        return -1;
    int m = (r + l) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
