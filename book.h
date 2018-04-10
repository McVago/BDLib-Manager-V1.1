#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "isbn.h"

using namespace std;

class Book
{
protected:
        ISBN isbn;
        string title,autor,year;
        int amount, total;

//Functions
public:
        Book *next;
        Book *previous;
        Book(ISBN paramisbn, string paramtitle, string paramautor, string paramyear, int paramamount);
        void lend();
        void back();
friend class List;
};

#endif // BOOK_H
