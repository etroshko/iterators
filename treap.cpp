#include <iostream>
#include <cstdlib>
#include "treap.h"

using namespace std;

Treap::Treap():
    root(0)
{}

Treap::~Treap()
{
    destroy(root);
}

Treap::Treap (const Treap &original)
{
    if (original.root)
    {
        root=new TreapNode(original.root->key, original.root->prior);
        copy(root, original.root);
    }
    else root=0;
}

void Treap::insert(int key)
{
    insert(root, key, rand()%100);
}

bool Treap::search(int key)
{
    return search(root, key);
}

void Treap::destroy()
{
    destroy(root);
}

void Treap::destroy(TreapNode *treap)
{
    if(treap)
    {
        destroy(treap->left);
        destroy(treap->right);
        delete treap;
        treap=0;
    }
}

void Treap::print()
{
    print(root,0);
}

int &Treap::asterisc_implementation(void *pointer)
{
    if(pointer)
        return ((TreapNode *)pointer)->key;
    else
        throw -1;
}

Treap::TreapNode* Treap::get_parent(TreapNode* pointer)
{
    if(pointer == root) return 0;

    TreapNode *current = root;
    while(current->left!= pointer && current->right!= pointer)
        current = pointer->key < current->key ? current->left : current->right;
    return current;
}

void *Treap::begin_implementation()
{
    TreapNode *current=root;
    if(current)
        while(current->left)
            current = current->left;

    return (void*)current;
}

void Treap::next_implementation(void *&pointer)
{
    TreapNode *current = (TreapNode *)pointer;
    TreapNode *temp;
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
            temp=get_parent(current);
            while(temp && current == temp->right)
            {
                current = temp;
                temp=get_parent(temp);
            }
            if(!get_parent(current))
                current = 0;
            else
                current = get_parent(current);
        }

        pointer = (void *)current;
    }
}

void Treap::previous_implementation(void *&pointer)
{
    TreapNode *current = (TreapNode *)pointer;
    TreapNode *temp;

    if(current)
    {
        if(current->left)
        {
            current = current->left;

            while(current->right)
                current = current->right;

            pointer = (void *)current;
        }
        else
        {
            temp=get_parent(current);
            while(temp && current == temp->left)
            {
                current = temp;
                temp=get_parent(temp);
            }

            if(get_parent(current))
                pointer = (void *)get_parent(current);
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
        pointer = (void*)current;
    }
}

void Treap::copy(TreapNode *&treap, TreapNode *original)
{
    if(!original)
        treap=0;
    else
    {
        treap=new TreapNode(original->key, original->prior);
        if(original->left)
            copy(treap->left,original->left);
        else
            treap->left=0;
        if(original->right)
            copy(treap->right,original->right);
        else
            treap->right=0;
    }
}

void Treap::insert(TreapNode *treap, int key, int prior)
{
    treap = new TreapNode(key, prior);

    TreapNode *l, *r;
    if(!search(key))
    {
        split(root, key, l , r);
        root=merge(l,treap);
        root=merge(root,r);
    }
}
void Treap::print(TreapNode *treap, int level)
{
    if(treap)
    {
        print(treap->left, level+1);
        for(int i=0; i<level; i++)
            std::cout<<"...";
        std::cout<<treap->key<<std::endl;
        print(treap->right,level+1);
    }
}


bool Treap::search(TreapNode *treap, int key)
{
    while(treap)
    {
        if (treap->key > key)
            treap=treap->left;
        else if (treap->key < key)
            treap=treap->right;
        else return true;
    }
    return false;
}

Treap::TreapNode *Treap::merge(TreapNode *l, TreapNode *r)
{
    if(!l||!r)
        return l?l:r;
    if(l->prior > r->prior)
    {
        l->right=merge(l->right, r);
        return l;
    }
    else
    {
        r->left=merge(l, r->left);
        return r;
    }
}

void Treap::split(TreapNode *t, int key, TreapNode *&l, TreapNode *&r)
{
    if(!t)
        l=r=0;

    else if(key<t->key)
    {
        split(t->left, key, l, t->left);
        r=t;
    }
    else
    {
        split(t->right, key, t->right, r);
        l=t;
    }
}
