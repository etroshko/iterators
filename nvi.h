#ifndef NVI_H
#define NVI_H

class Iterator;

class NVI
{
public:
    friend class Iterator;
    NVI() {}
    NVI(const NVI &orig);
    ~NVI();

    void insert_element(int);
    bool search_element(int);
    void destroy_set();
    void output();

    Iterator begin();
    Iterator end();

private:

    virtual void insert(int) = 0;
    virtual bool search(int) = 0;
    virtual void destroy() = 0;
    virtual void print() = 0;

    int &asterisc(void*);
    void next(void*&);
    void previous(void*&);

    virtual int &asterisc_implementation(void*) = 0;
    virtual void next_implementation(void*&) = 0;
    virtual void previous_implementation(void*&) = 0;
    virtual void *begin_implementation() = 0;
};


class Iterator
{
public:
    friend class NVI;

    Iterator();
    ~Iterator();
    Iterator (NVI*, void*);

    int &operator*();
    Iterator operator++();
    Iterator operator++(int);

    bool operator==(const Iterator&);
    bool operator!=(const Iterator&);

private:
    NVI *owner;
    void *current;
};

#endif
