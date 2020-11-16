const int maxTerms = 10;

template <typename T> class SparseMatrix;

template <typename T> class Trituple {
    friend class SparseMatrix<T>;
    private:
        int row, col;
        T data;
};

template <typename T> class SparseMatrix {
    public:
        SparseMatrix(int maxRow, int maxCol);
        SparseMatrix<T> mat_transpose(SparseMatrix<T> b);
        SparseMatrix<T> max_fast_transpose(SparseMatrix<T> b);
        SparseMatrix<T> multiply(SparseMatrix<T> b);
    private:
        int rows, cols, nonzero_terms;
        Trituple<T> smarray[maxTerms];
};

template <typename T> SparseMatrix<T> SparseMatrix<T>::mat_transpose(SparseMatrix<T> b) {
    int currentPosition;
    b.rows = cols;
    b.cols = rows;
    b.nonzero_terms = nonzero_terms;
    if (nonzero_terms > 0) {
        currentPosition = 0;
        for (int k = 0; k < cols; k++) {
            for (int i = 0; i < nonzero_terms; i++) {
                if (smarray[i].col == k) {
                    b.smarray[currentPosition].row = k;
                    b.smarray[currentPosition].col = smarray[i].row;
                    b.smarray[currentPosition].data = smarray[i].data;
                    currentPosition++;
                }
            }
        }
    }
    return b;
}

template <typename T> SparseMatrix<T> SparseMatrix<T>::max_fast_transpose(SparseMatrix<T> b) {
    int i, j;
    int *x = new int[cols];
    int *y = new int[cols];
    b.rows = cols;
    b.cols = rows;
    b.nonzero_terms = nonzero_terms;
    if (nonzero_terms > 0) {
        for (i = 0; i < cols; i++) {
            x[i] = 0;
        }
        for (i = 1; i < nonzero_terms; i++) {
            x[smarray[i].col]++;
        }
        y[0] = 0;
        for (i = 1; i <= cols; i++) {
            y[i] = y[i - 1] + x[i - 1];
        }
        for (i = 1; i <= nonzero_terms; i++) {
            j = y
        }
    }
}
