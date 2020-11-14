template <typename T> BinaryTree<T> *BinarryTree<T>::createBinaryTree(T *VLR, T *LVR, int n) {
    if (n == 0) {
        return NULL;
    }
    int k = 0;
    while (VLR[0] != LVR[k])
        k++;
    BinTreeNode <T> *t = new BinTreeNode<T> (VLR[0]);
    t->leftChild = createBinaryTree(VLR + 1, LVR, k);
    t->rightChild = createBinaryTree(VLR + K + 1, LVR + K + 1, n - k - 1);
    return t;
}
