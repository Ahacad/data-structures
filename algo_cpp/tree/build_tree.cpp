struct Node {
    char data;
    // left child
    Node *left;
    // right child
    Node *right;
};

Node *pre_in(string &preorder, string &inorder, int &preindex, int start, int end) {
    if (start > end)
        return nullptr;
    Node *root = new Node();
    root->data = preorder[preindex];
    int idx = fdidx(inorder, preorder[preindex++]);
    root->left = pre_in(preorder, inorder, preindex, start, idx - 1);
    root->right = pre_in(preorder, inorder, preindex, idx + 1, end);
    return root;
}
