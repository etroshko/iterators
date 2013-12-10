#ifndef TREAP_H
#define TREAP_H

#include "nvi.h"

class Treap: public NVI
{
public:
    struct TreapNode
    {
        int key;
        int prior;
        TreapNode *left;
        TreapNode *right;
       // TreapNode(){}

        TreapNode(int key, int prior):
            key(key), prior(prior), left(0), right(0)
        {}
    };
    TreapNode *root;
    Treap();
    Treap (const Treap&);
    ~Treap();
    Treap &operator=(const Treap&);

private:

    void insert(int);
    bool search(int);
    void destroy();
    void print();

    void insert(TreapNode*, int, int);
    bool search(TreapNode*, int);
    void destroy(TreapNode *);
    void print(TreapNode*, int);
    void copy(TreapNode*&, TreapNode*);
    TreapNode* merge(TreapNode*, TreapNode*);
    void split(TreapNode*, int, TreapNode*&, TreapNode*&);
    TreapNode* get_parent(TreapNode*);

    int &asterisc_implementation(void*);
    void next_implementation(void*&);
    void previous_implementation(void*&);
    void *begin_implementation();

};

#endif
