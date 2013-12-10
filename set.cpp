#include <iostream>
#include "set.h"

Set::Set():
    object(0)
{}

Set::Set(NVI *object):
    object(object)
{}

Set::~Set()
{
    destroy();
}

void Set::insert_key(int key)
{
    object->insert_element(key);
}

int Set::search_key(int key)
{
    return object->search_element(key);
}

void Set::output_tree()
{
    object->output();
}

void Set::output_set()
{
    for(Iterator it=object->begin(); it!=object->end(); it++)
        std::cout << *it << " ";
}
void Set::destroy()
{
    object->destroy_set();
}

Set &Set::operator=(const Set &orig)
{
    *(this->object) = *(orig.object);
    return *this;
}

