#include "iostream"
#include "binary_tree.h"
#include "CQue.h"
#include "Stack.h"

using namespace std;

binary_tree::binary_tree(int value) {
    root.node_value=value;
    node_count=0;
}

void binary_tree::insert(binary_tree *value, binary_tree *parent) {
    if(parent->root.left== nullptr){
        parent->root.left=&value->root;
    }
    else if(parent->root.right== nullptr){
        parent->root.right=&value->root;
    }
    else{ return;}
    value->root.parent_node=&parent->root;
    node_count++;
}

int binary_tree::node_counter(Node *t) {
    if(t->left == nullptr){
        return 1;
    }
    else if(t->right== nullptr){
        return 1+ node_counter(t->left);
    }
    else{
        return 1 + node_counter(t->left) + node_counter(t->right);
    }
}

int binary_tree::height(Node *t) {
    if(t->left == nullptr){
        return 0;
    }
    else if(t->right == nullptr){
        return 1+ height(t->left);
    }
    else{
        int l = height(t->left);
        int r = height(t->right);
        if(l >= r){return 1+l;}
        return 1+r;
    }
}

void binary_tree::BFS(binary_tree *t) {

    int size=t->node_counter(&t->root);
    CQue<Node*> bfs(size);
    bfs.Insert(&t->root);
    while (!bfs.IsEmpty()){
        Node *ptr = bfs.Delete();
        cout<<ptr->node_value<<"\t";
        if(ptr->left != nullptr && ptr->right != nullptr){
            bfs.Insert(ptr->left);
            bfs.Insert(ptr->right);
        }
        else if(ptr->left != nullptr && ptr->right == nullptr){
            bfs.Insert(ptr->left);
        }
    }
}

void binary_tree::DFS(binary_tree *t) {
    int size=t->node_counter(&t->root);
    Stack<Node*> dfs(size);
    dfs.Push(&t->root);
    while (!dfs.IsEmpty()){
        Node *ptr = dfs.Pop();
        cout<<ptr->node_value<<"\t";
        if(ptr->left != nullptr && ptr->right != nullptr){
            dfs.Push(ptr->right);
            dfs.Push(ptr->left);
        }
        else if(ptr->left != nullptr && ptr->right == nullptr){
            dfs.Push(ptr->left);
        }
    }
}

void binary_tree::InOrder(Node *t) const {
    if(t->left != nullptr){
        InOrder(t->left);
    }

    cout<<t->node_value<<"\t";

    if(t->right != nullptr){
        InOrder(t->right);
    }
}

void binary_tree::PreOrder(Node *t) const {
    cout<<t->node_value<<"\t";

    if(t->left != nullptr){
        PreOrder(t->left);
    }

    if(t->right != nullptr){
        PreOrder(t->right);
    }
}

void binary_tree::PostOrder(Node *t) const {
    if(t->left != nullptr){
        PostOrder(t->left);
    }

    if(t->right != nullptr){
        PostOrder(t->right);
    }

    cout<<t->node_value<<"\t";
}