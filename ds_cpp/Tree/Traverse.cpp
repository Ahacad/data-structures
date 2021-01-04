#include <queue>
#include <iostream>

// binary tree
struct Node {
    Node *left, *right;
    int data;
    Node() {
        left = nullptr;
        right = nullptr;
        data = -1;
    }
    Node(Node *_left, Node *_right, int _data) {
        left = _left;
        right = _right;
        data = _data;
    }
};

int levelorder(Node *node); 
int preorder_recursive(Node *node); 
int preorder_nonrecursive(Node *node); 
int inorder_recursive(Node *node); 
int inorder_nonrecursive(Node *node); 
int postorder_recursive(Node *node); 
int postorder_nonrecursive(Node *node); 

int levelorder(Node *node) {
    std::queue< std::pair<int, Node *> > q;
    q.push(std::make_pair(0, node));
    std::pair<int, Node*> tmp;
    while (!q.empty()) {
        tmp = q.front(); q.pop();
        std::cout << tmp.second->data << " ";
        if (tmp.second->left != nullptr) 
            q.push(std::make_pair(tmp.first+1, tmp.second->left));
        if (tmp.second->right != nullptr) 
            q.push(std::make_pair(tmp.first+1, tmp.second->right));
    }
    return 0;
}

int preorder_recursive(Node *node) {

}
