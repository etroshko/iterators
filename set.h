#ifndef SET_H
#define SET_H

#include "nvi.h"

class Set
{
public:

    Set(NVI *object);

    ~Set();

    void insert_key (int);
    int search_key (int);
    void destroy();

    void output_tree();
    void output_set();

    Set &operator=(const Set&);
    Set operator+(Set&);
    Set operator-(Set&);
    Set operator^(Set&);

private:
    Set();
    NVI *object;

};


#endif
