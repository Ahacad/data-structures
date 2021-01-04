template <typename T> int partition(T a[], int l, int r) {
    int i = l - 1, j = r;
    T t = a[r];
    for (;;) {
        while(a[++i] < t);
        while(a[--j] > t)
            if (j == l)
                break;
        if (i >= j)
            break;
        swap(a[i], a[j]);
    }
    swap(a[i], a[r]);
    return i;
}
template <typename T> void QuickSort(T a[], int l, int r) {
    int i;
    if (r <= l)
        return ;
    i = partition(a, l, r);
    QuickSort(a, l, i - 1);
    QuickSort(a, i + 1, r);
}
