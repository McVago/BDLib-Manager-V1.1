#include "book.h"
#include "isbn.h"
#include <iostream>
using namespace std;

Book::Book(ISBN paramisbn, string paramtitle, string paramautor, string paramyear, int paramamount){
      isbn = paramisbn;
      title = paramtitle;
      autor = paramautor;
      year = paramyear;
      amount = paramamount;
      total = paramamount;
      next = NULL;
      previous = NULL;
    }
    void Book::lend(){
      if (amount != 0) amount--;
      else throw "All books are occupied";
    }
    void Book::back(){
        if(amount!=total) amount++;
        else throw "There are no books occupied";
    }

