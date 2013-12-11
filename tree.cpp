#include "tree.h"
#include <iostream>

Tree::Tree():
    root(0) {}

Tree::Tree (const Tree &original)
{
    if (original.root)
    {
        root=new TreeNode(original.root->key);
        copy(root, original.root);
    }
    else root=0;
}

Tree::~Tree ()
{
    destroy();
}

void Tree::destroy()
{
    destroy(root);
}

void Tree::insert(int val)
{
    insert(root, val);
}
bool Tree::search(int key)
{
    return search(root, key);
}
/*void Tree::remove(int val)
{
    remove(root, val);
}*/
void Tree::destroy(TreeNode *&ptr)
{
    if(ptr)
    {
        destroy(ptr->left);
        destroy(ptr->right);
        delete ptr;
    }
}
void Tree::print()
{
    print(root,0);
}
//////////////////////////////////////////////////////////////

int &Tree::asterisc_implementation(void *ptr)
{
    if(ptr)
        return ((TreeNode *)ptr)->key;
    else
        throw -1;
}

Tree::TreeNode* Tree::get_parent(TreeNode* ptr)
{
    if(ptr == root) return 0;

    TreeNode *current = root;
    while(current->left!= ptr && current->right!= ptr)
        current = ptr->key < current->key ? current->left : current->right;
    return current;
}

void *Tree::begin_implementation()
{
    TreeNode *current=root;
    if(current)
        while(current->left)
            current = current->left;

    return (void*)current;
}

void Tree::next_implementation(void *&ptr)
{
    TreeNode *current = (TreeNode *)ptr;
    TreeNode *y;
    if(current)
    {
        if(current->right)
        {
            current = current->right;

            while(current->left)
                current = current->left;
        }
        else
        {
            y=get_parent(current);
            while(y && current == y->right)
            {
                current = y;
                y=get_parent(y);
            }
            if(!get_parent(current))
                current = 0;
            else
                current = get_parent(current);
        }

        ptr = (void *)current;
    }
}

void Tree::previous_implementation(void *&ptr)
{
    TreeNode *current = (TreeNode *)ptr;
    TreeNode *y;

    if(current)
    {
        if(current->left)
        {
            current = current->left;

            while(current->right)
                current = current->right;

            ptr = (void *)current;
        }
        else
        {
            y=get_parent(current);
            while(y && current == y->left)
            {
                current = y;
                y=get_parent(y);
            }

            if(get_parent(current))
                ptr = (void *)get_parent(current);
            else
                return;
        }
    }
    else
    {
        current = root;
        if(current)
            while(current->right)
                current = current->right;
        ptr = (void*)current;
    }
}


void Tree::copy(TreeNode *&tree, TreeNode *original)
{
    if(!original)
        tree=0;
    else
    {
        tree=new TreeNode(original->key);
        if(original->left)
            copy(tree->left,original->left);
        else
            tree->left=0;
        if(original->right)
            copy(tree->right,original->right);
        else
            tree->right=0;
    }
}
void Tree::insert(TreeNode *&tree, int key)
{
    if (tree==0)
        tree=new TreeNode(key);
    else if (key < tree->key)
        insert(tree->left,key);

    else if (key > tree->key)
        insert(tree->right, key);

}
bool Tree::search(TreeNode *t, int key)
{

    while(t)
    {
        if (t->key > key)
            t=t->left;
        else if (t->key < key)
            t=t->right;
        else return true;
    }
    return false;



}


void Tree::print(TreeNode *t, int level)
{
    if(t)
    {
        print(t->left, level+1);
        for(int i=0; i<level; i++)
            std::cout<<"...";
        std::cout<<t->key<<std::endl;
        print(t->right,level+1);
    }
}
