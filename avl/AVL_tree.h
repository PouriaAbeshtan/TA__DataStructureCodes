#pragma once

class AVL_tree {
public:
    //variables
    //AVL_tree *parent_node= nullptr;
    AVL_tree *left= nullptr;
    int node_value;
    AVL_tree *right= nullptr;
    //int node_count;

    //methods
    AVL_tree(int value);
    AVL_tree *insert(AVL_tree *n, AVL_tree *root);
    int node_counter(AVL_tree *t);
    int height(AVL_tree *t);
    void PreOrder(AVL_tree *t) const;
};
