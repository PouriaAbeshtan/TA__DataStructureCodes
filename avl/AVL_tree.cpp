// #include "AVL_tree.h"
// #include "iostream"

// using namespace std;

// AVL_tree::AVL_tree(int value) {
//     node_value = value;
// }

// int max(int a, int b){
//     if (a >= b) {
//         return a;
//     } else {
//         return b;
//     }
// }

// int AVL_tree::height(AVL_tree *t) {
//     if(t == nullptr){
//         return -1;
//     }
//     else if (left == nullptr && right == nullptr) {
//         return 0;
//     }
//     else if (right == nullptr) {
//         return 1 + left->height(left);
//     }
//     else if(left == nullptr) {
//         return 1 + right->height(right);
//     }
//     else {
//         int l = left->height(left);
//         int r = right->height(right);
//         return 1+ max(l, r);
//     }
// }

// int difference(AVL_tree *n) {
//     if (n == nullptr) {
//         return 0;
//     } else {
//         return n->left->height(n->left) - n->right->height(n->right);

//     }
// }
// AVL_tree *LL(AVL_tree *n){
//     AVL_tree *l = n->left;
//     AVL_tree *lr = l->right;

//     l->right = n;
//     n->left = lr;

//     return l;
// }

// AVL_tree *RR(AVL_tree *n){
//     AVL_tree *r = n->right;
//     AVL_tree *rl = r->left;

//     r->left = n;
//     n->right = rl;

//     return r;
// }

// AVL_tree *AVL_tree::insert(AVL_tree *n, AVL_tree *root) {
//     if(root == nullptr){
//         return n;
//     }
//     else if(n->node_value < root->node_value){
//         root->left = insert(n,root->left);
//     }
//     else if(n->node_value > root->node_value){
//         root->right = insert(n,root->right);
//     }
//     else{
//         return n;
//     }

//     int different = difference(root);

//     if(different > 1){
//         if(n->node_value < root->left->node_value){
//             return LL(root);
//         } else{
//             root->left = RR(root->left);
//             return LL(root);
//         }
//     }
//     else if(different < -1){
//         if(n->node_value > root->right->node_value){
//             return RR(root);
//         } else{
//             root->right = LL(root->right);
//             return RR(root);
//         }
//     }
//     return root;
// }

// void AVL_tree::PreOrder(AVL_tree *t) const {
//     cout<<t->node_value<<"\t";

//     if(t->left != nullptr){
//         PreOrder(t->left);
//     }

//     if(t->right != nullptr){
//         PreOrder(t->right);
//     }
// }


#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b);
int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node *newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key) {
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}


