#pragma once

struct Node{
    Node *parent_node= nullptr;
    struct Node *left= nullptr;
    int node_value;
    struct Node *right= nullptr;
};

class binary_tree {
public:
    Node root;
    int node_count;

    binary_tree(int value);
    void insert(binary_tree *value, binary_tree *parent);
    int node_counter(Node *t);
    int height(Node *t);
    void BFS(binary_tree *t);
    void DFS(binary_tree *t);
    void InOrder(Node *t) const;
    void PreOrder(Node *t) const;
    void PostOrder(Node *t) const;
};