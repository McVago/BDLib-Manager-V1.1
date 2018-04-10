#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "list.h"
#include <fstream>
#include <iostream>
using namespace std;
class functions{
public:
    functions(){}
  void load(List& list,string archive);
  void savefile(List& list,string file);
  void insert(List &list,string String);
  void erase(List &list,string String);
  void get(List &list,string String);
};

#endif // FUNCTIONS_H
