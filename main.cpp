#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "treap.h"
#include "tree.h"
#include "set.h"
#include "nvi.h"

using namespace std;

int main()
{
    srand(time(0));
    Treap *a=new Treap;
    Tree *b=new Tree;
    Set set(a);
    Set set2(b);

    int key;
    fstream file;
    file.open("111.txt");
    cout<<"Treap: "<<endl;
    while(!file.eof())
    {
        file>>key;
        set.insert_key(key);
    }
    file.close();
    set.output_tree();
    cout<<endl;
    cout<<"Treap Iterator: ";
    set.output_set();
    cout<<endl<<endl;

    cout<<"Tree: "<<endl;

    fstream file2;
    file2.open("222.txt");
    while(!file2.eof())
    {
        file2>>key;
        set2.insert_key(key);
    }
    file2.close();
    set2.output_tree();
    cout<<endl;
    cout<<"Tree Iterator:";
    set2.output_set();
    cout<<endl;

    return 0;
}
