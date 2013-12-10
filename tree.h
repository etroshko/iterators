#ifndef TREE_H
#define TREE_H

#include "nvi.h"

class Tree: public NVI
{
public:

    struct TreeNode
    {
        int key;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int key):
            key(key), left(0), right(0)
        {}
    };
    TreeNode *root;
    Tree();
    //Tree(const NVI*);
    Tree (const Tree&);
    ~Tree();
private:

    void insert(int);
    bool search(int);
    void destroy();
    void print();

    void insert(TreeNode*&, int);
    bool search(TreeNode*, int);
    void destroy(TreeNode*&);
    void print(TreeNode*,int);
    void copy(TreeNode*&, TreeNode*);
    TreeNode *get_parent(TreeNode*);

    int &asterisc_implementation(void*) ;
    void next_implementation(void*&);
    void previous_implementation(void*&);
    void *begin_implementation();

};

#endif
