#include "nvi.h"
#include "treap.h"

NVI::~NVI()
{
    destroy_set();
}

void NVI::insert_element(int key)
{
    insert(key);
}

bool NVI::search_element(int key)
{
    return search(key);
}

void NVI::destroy_set()
{
    destroy();
}

void NVI::output()
{
    print();
}

Iterator::Iterator():
    owner(0),
    current(0)
{}

Iterator::Iterator(NVI *owner, void *current):
    owner(owner),
    current(current)
{}

Iterator::~Iterator()
{
    owner = 0;
    current = 0;
}

int &Iterator::operator*()
{
    if(owner)
        return owner->asterisc(current);
    else throw -1;
}

Iterator Iterator::operator++()
{
    if(owner)
        owner->next(current);
    return *this;
}

Iterator Iterator::operator++(int)
{
    Iterator result(*this);
    ++(*this);
    return result;
}

bool Iterator::operator==(const Iterator &original)
{
    return owner == original.owner && current == original.current;
}

bool Iterator::operator!=(const Iterator &original)
{
    return !(*this == original);
}

/////////////////////////////////////////////
int &NVI::asterisc(void *ptr)
{
    return asterisc_implementation(ptr);
}

Iterator NVI::begin()
{
    return Iterator(this, begin_implementation());
}

Iterator NVI::end()
{
    return Iterator(this, 0);
}

void NVI::next(void *&ptr)
{
    next_implementation(ptr);
}

void NVI::previous(void *&ptr)
{
    previous_implementation(ptr);
}
