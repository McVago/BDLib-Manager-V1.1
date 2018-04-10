#include <fstream>
#include <iostream>
#include "functions.h"
using namespace std;

void functions::load(List& list,string archive){
  ifstream infile;
  infile.open(archive, ifstream::in);
  string b;
  if (!infile.good()){throw "Archive doesn't exists";}
  while (infile.good()){//While file not ended, will read to the end
    char a = infile.get();
    int c = a;
    if(c == 10){//To ignore ASCII 10 (\n)
    insert(list,b);
  }
    else{
      b = b + a;
    }
  }
  infile.close();
}

void functions::savefile(List& list,string file){
  string textToSave;
  textToSave = list.printfile();
  fstream outfile;
  outfile.open(file, ios::out);
  outfile << textToSave;
  outfile.close();
}

void functions::insert(List& list,string String){
  string paramisbn,title,autor,year;
  int amount = 0;
  int i = 0;
  int cont = 0;
  while(String[i]){
    char a = String[i];
    if(a == ';')cont++;
    int c = a;
    i++;
    if(a!=';'){
    if (cont == 0){ paramisbn = paramisbn + a; }
    if (cont == 1){ title = title + a; }
    if (cont == 2){ autor = autor + a; }
    if (cont == 3){ year = year + a; }
    if (cont == 4){ amount = amount + (c-48); }}
  }
  ISBN isbn = ISBN(paramisbn);
  bool result = isbn.verificar();
  if (result){
    list.addlast(isbn,title,autor,year,amount);
    }
  else{throw "Error verifying the isbn";}
  }

void functions::erase(List& list, string String){
  try{
    list.erase(String);
  }
  catch(const char* msg){
    cout << msg << endl;
  }
}
void functions::get(List& list,string String){
  string isbn,user;
  int i = 0;
  int cont = 0;
  while(String[i]){
    char a = String[i];
    if(a == ';')cont++;
    i++;
    if(a!=';'){
    if (cont == 0){ isbn = isbn + a; }
    if (cont == 1){ user = user + a; }}}
  try{
    list.lend(isbn);
  }
  catch(const char* msg){
    cout << msg << endl;
  }
}

