#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "book.h"
#include <vector>
#include <sstream>

using namespace std;
typedef Book* bookp;
class List{
private:
        bookp first;
        bookp current;
        bookp last;
public:
        List();
        vector<string> index(string what);
        List indexname(string what,string string);
        int lenght();
        void addfirst(ISBN isbn, string title, string autor,string year,int amount);
        void addlast(ISBN isbn, string title, string autor,string year,int amount);
        void erase(ISBN isbn);
        void lend(ISBN isbn);
        void print();
        string printfile();
        bool empty();
        void List::mergeSort(List &list,string String);
        List sortedMerge(List a, List b,string String);

};
#endif // LIST_H
