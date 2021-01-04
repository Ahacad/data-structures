const int delta[] = {4, 3, 1};
const int t = 3;
template<typename T> int ShellSort(T a[], int l, int r) {
    int h, m, i, j; T v;
    for (m = 0; m < t; m++) {
        for (h = delta[m], i = l + h; i <= r; i++, a[j] = v) {
            for (j = i, v = a[i]; j >= l + h && v < a[j - h]; j -= h) {
                a[j] = a[j - h];
            }
            a[j] = v;
        }
    }
    return 0;
}
