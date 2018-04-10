#include "list.h"
#include <iostream>
#include <vector>
using namespace std;

List::List(){first = NULL; last = NULL;}

bool List::empty(){if (!first) return true;else return false;}
void List::addfirst(ISBN isbn, string title, string autor,string year,int amount){
   if (empty()){
     first = new Book(isbn,title,autor,year,amount);
     last = first;
   }else{
        bookp added = new Book(isbn,title,autor,year,amount);
        added->next = first;
        first->previous = added;
        first = added;
   }
}
void List::addlast(ISBN isbn, string title, string autor,string year,int amount){
        if (empty()){
                first = new Book(isbn,title,autor,year,amount);
                last = first;
        }else{
                bookp added = new Book (isbn,title,autor,year,amount);
                added->previous = last;
                last->next = added;
                last = added;
        }
}
void List::erase(ISBN isbn){
  if(empty()){throw "Empty list";}
  else{
    bookp temp = first;
    for (int i = 0; i<this->lenght(); i++){
        temp = temp->next;
        if(temp->isbn.nuevo == isbn.nuevo){
          if (temp->amount != temp->total){
            throw "Someone has the book";
          }
        }

    }

    if (temp->previous->next){temp->previous->next = temp->next;}
    if(temp->next->previous){temp->next->previous = temp->previous;}
    delete temp;
  }
}
int List::lenght(){
        int cont = 0;
    bookp aux = first;
    if(empty()){
        return cont;
    }else{
        while(aux){
          aux=aux->next;
          cont++;
        }
        return cont;}
}
void List::lend(ISBN isbn){
  bool could = false;
  if (empty()){throw "Empty list";}
  else{
    bookp aux = first;
    while(aux){
      if(isbn.nuevo == aux->isbn.nuevo){
        aux->lend();
        could = true;
        break;
      }
      aux = aux->next;
    }
    if(!could){throw "Book not found";}
  }
}
List List::indexname(string what, string String){
    List list;
    if (empty()){throw "Empty list";}
    else{
        if(what == "r"){
          bookp aux = first;
          while(aux){
            if(String == aux->isbn.pais){
              list.addfirst(aux->isbn,aux->title,aux->autor,aux->year,aux->amount);
            }
            aux = aux->next;
            }
        }
      if(what == "e"){
          bookp aux = first;
          while(aux){
            if(String == aux->isbn.editorial){
              list.addfirst(aux->isbn,aux->title,aux->autor,aux->year,aux->amount);
            }
            aux = aux->next;
            }
      }
      if(what == "a"){
          bookp aux = first;
          while(aux){
            if(String == aux->autor){
              list.addfirst(aux->isbn,aux->title,aux->autor,aux->year,aux->amount);
            }
            aux = aux->next;
            }
      }
      if(what == "y"){
          bookp aux = first;
          while(aux){
            if(String == aux->year){
              list.addfirst(aux->isbn,aux->title,aux->autor,aux->year,aux->amount);
            }
            aux = aux->next;
            }
      }
      return list;
    }
}
vector<string> List::index(string what){
    vector<string> list(100,0);
    int i = 0;
    if (empty()){throw "Empty list";}
    else{
        if(what == "r"){
          bookp aux = first;
          while(aux){
            for(int j = 0;j<=i;j++){
                bool flag = true;
                if(list[j] != aux->isbn.pais){
                    flag = false;
                }
                if (flag == true)break;
                if(j == i && flag == false){list[i] = aux->isbn.pais;i++;}
            }
            aux = aux->next;
            }
        }
      if(what == "e"){
          bookp aux = first;
          while(aux){
            for(int j = 0;j<=i;j++){
                bool flag = true;
                if(list[j] != aux->isbn.editorial){
                    flag = false;
                }
                if (flag == true)break;
                if(j == i && flag == false){list[i] = aux->isbn.editorial;i++;}
            }
            aux = aux->next;
            }
      }
      if(what == "a"){
          bookp aux = first;
          while(aux){
            for(int j = 0;j<=i;j++){
                bool flag = true;
                if(list[j] != aux->autor){
                    flag = false;
                }
                if (flag == true)break;
                if(j == i && flag == false){list[i] = aux->autor;i++;}
            }
            aux = aux->next;
            }
      }
      if(what == "y"){
          bookp aux = first;
          while(aux){
            for(int j = 0;j<=i;j++){
                bool flag = true;
                if(list[j] != aux->year){
                    flag = false;
                }
                if (flag == true)break;
                if(j == i && flag == false){list[i] = aux->year;i++;}
            }
            aux = aux->next;
            }
      }
      return list;
    }
}
void List::print(){
    if(empty()){throw "Empty List";}
    else{
        string A,B,C,D,E,F,G;
        A = "ISBN";
        B = "Title";
        C = "Autor";
        D = "Year";
        E = "Region";
        F = "Editorial";
        G = "=======";
        cout << A << "\t\t\t" << B << "\t" << C << "\t" << D << "\t" << E << "\t" << F << "\t" << endl;
        cout << G<<G<<G << "\t" << G << "\t" << G << "\t" << G << "\t" << G << "\t" << G << "\t" << endl;
        bookp aux = first;
        while(aux){
            cout << aux->isbn.nuevo << "\t" << aux->title << "\t" << aux->autor << "\t"
                 << aux->year << "\t" << aux->isbn.pais << "\t" << aux->isbn.editorial << "\t" << endl;
            aux=aux->next;
        }
    }
}
string List::printfile(){
    if(empty()){throw "Emptylist";}
    else{
        string A;
        bookp aux = first;
        while(aux){
            ostringstream ss;
            ss << aux->amount;
            A = A + aux->isbn.nuevo;
            A = A + ";";
            A = A + aux->title;
            A = A + ";";
            A = A + aux->autor;
            A = A + ";";
            A = A + aux->year;
            A = A + ";";
            A = A + ss.str();
            A = A + "\n";
            aux=aux->next;
        }
        return A;
    }
}
void List::mergeSort(List &list,string String){
    bookp head = list.first;
    list a;
    list b;

    if ((head == NULL) || (head->next == NULL)){
        return;
    }
    FrontBackSplit(head,a,b);
    mergeSort(a)
}
List sortedMerge(List a, List b,string String){
    bookp result;
    string lel = a.first->autor;
    if (a == NULL)return b;
    else if(b == NULL)return a;

    if ()
}
