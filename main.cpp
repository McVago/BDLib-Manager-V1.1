#include <QCoreApplication>
#include "isbn.h"
#include "book.h"
#include "list.h"
#include "stack.h"
#include "functions.h"
#include "index.h"

enum action {load,save,savef,index,ls,insert,erase,gett,clear};

int main()
{
    Index<List> indexe;
    Index<List> indexr;
    Index<List> indexa;
    Index<List> indexy;
    string file;
    List indexedname;
    int what = -1;
    functions XX;
    string AA1 = "Welcome to BDLibManager V1.0";
    string AA2 = "Please type what you want to do:";
    string AA3 = "For a list of functions type help";
    string AA4 = "Type the name of the file you wish to load";
    string AA5 = "Saving...";
    string AA6 = "Type the name of the file you wish to be saved";
    string AA7 = "Please what type of index you want using index -r -e -a -y";
    string AB1 = "List of functions are: 0-load 1-save 2-savef 3-index 4-ls 5-insert 6-erase 7-get 8-clear";
    string AB2 = "Please insert a string for example:0-555-55555-5;title;autor;year;amount";
    string AB3 = "Insert the ISBN of the book you want to erase";
    string AB4 = "Insert the ISBN of the book you want to get, and your name followed by a ; for example:0-555-55555-5;paul";
    string AA8 = "Please what type of index you want using ls -r -e -a -y";
      STACK<string, 100> stack;
      List DataBase;
      string z ="y";
      while(z=="Y" || z=="y"){
      cout << AA1 << endl << AA2 << endl << AA3 << endl<< AB1 << endl;
      cin >> what;
      string b;
      string c;
      string isbn,user;
      int i = 0;
      int cont = 0;
      switch (what) {
        case load:
          cout << AA4 << endl;
          cin >> b;
          b = b + ".txt";
          file = b;
          try{
          XX.load(DataBase,b);}
          catch(const char* msg){
              cout << msg << endl;
          }
          break;
        case save:
          cout << AA5 << endl;
          XX.savefile(DataBase,file);
          break;
        case savef:
          cout << AA6 << endl;
          cin >> b;
          b = b + ".txt";
          file = b;
          XX.savefile(DataBase,b);
          break;
        case index:
          //INDEX CODE
          cout << AA7 << endl;
          cin >> b;
          c = b[6];
          if(c == "r"){
              c = "r";
              try{
                  vector<string> testo = DataBase.index("r");
                  for(int i = 0;testo[i]!="0";i++){
                      List temp;
                      try{
                          temp = DataBase.indexname("r",testo[i]);
                          indexr.Insert(temp);
                      }catch(const char* msg){cout << msg << endl;}
                  }
              }catch(const char* msg){cout << msg << endl;}
          }
          if(c == "e"){
              c = "e";
              try{
                  vector<string> testo = DataBase.index("e");
                  for(int i = 0;testo[i]!="0";i++){
                      List temp;
                      try{
                          temp = DataBase.indexname("e",testo[i]);
                          indexe.Insert(temp);
                      }catch(const char* msg){cout << msg << endl;}
                  }
              }catch(const char* msg){cout << msg << endl;}
          }
          if(c == "a"){
              c = "a";
              try{
                  vector<string> testo = DataBase.index("a");
                  for(int i = 0;testo[i]!="0";i++){
                      List temp;
                      try{
                          temp = DataBase.indexname("a",testo[i]);
                          indexa.Insert(temp);
                      }catch(const char* msg){cout << msg << endl;}
                  }
              }catch(const char* msg){cout << msg << endl;}
          }
          if(c == "y"){
              c = "y";
              try{
                  vector<string> testo = DataBase.index("y");
                  for(int i = 0;testo[i]!="0";i++){
                      List temp;
                      try{
                          temp = DataBase.indexname("y",testo[i]);
                          indexy.Insert(temp);
                      }catch(const char* msg){cout << msg << endl;}
                  }
              }catch(const char* msg){cout << msg << endl;}
          }
          break;
      case ls:
          cout << AA8 << endl;
          cin >> b;
          c = b[3];
          if(c == "r"){
              string name;
              char alpha = b[5];
              for(int i = 5;alpha!=')';i++){
                  name = name + b[i];
                  alpha = b[i+1];
              }
              try{
                  indexedname = DataBase.indexname("r",name);
                  indexedname.print();
              }catch(const char* msg){cout<<msg<<endl;}
          }
          if(c == "e"){
              string name;
              char alpha = b[5];
              for(int i = 5;alpha!=')';i++){
                  name = name + b[i];
                  alpha = b[i+1];
              }
              try{
                  indexedname = DataBase.indexname("e",name);
                  indexedname.print();
              }catch(const char* msg){cout<<msg<<endl;}
          }
          if(c == "a"){
              string name;
              char alpha = b[5];

              for(int i = 5;alpha!=')';i++){
                  name = name + b[i];
                  alpha = b[i+1];
              }
              try{
                  indexedname = DataBase.indexname("a",name);
                  indexedname.print();
              }catch(const char* msg){cout<<msg<<endl;}
          }
          if(c == "y"){
              string name;
              char alpha = b[5];
              for(int i = 5;alpha!=')';i++){
                  name = name + b[i];
                  alpha = b[i+1];
              }
              try{
                  indexedname = DataBase.indexname("y",name);
                  indexedname.print();
              }catch(const char* msg){cout<<msg<<endl;}
          }
          break;
      case insert:
          cout<< AB2 << endl;
          cin >> b;
          try{XX.insert(DataBase,b);
            }catch(const char* msg){
              cout << msg <<endl;
          }
          break;
      case erase:
          cout << AB3 << endl;
          cin >> b;
          try{
            XX.erase(DataBase,b);
      }catch(const char* msg){cout << msg << endl;}
          break;
      case gett:
          cout << AB4 << endl;
          cin >> b;
          while(b[i]){
            char a = b[i];
            if(a == ';')cont++;
            i++;
            if(a!=';'){
            if (cont == 0){ isbn = isbn + a; }
            if (cont == 1){ user = user + a; }}}
          try{XX.get(DataBase,isbn);cout<< "Book lended to :"<< user << endl;}
          catch(const char* msg){cout << msg << endl;}
      case clear:
          main();
      }
      DataBase.print();
      cout<< "want to continue? Y/n" <<endl;
      cin>>z;
    }
        }
