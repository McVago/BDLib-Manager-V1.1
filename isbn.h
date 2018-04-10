#ifndef ISBN_H
#define ISBN_H
#include <iostream>

using namespace std;

class ISBN
{

public:
    ISBN();
    ISBN(string cadena);
    bool verificar();


protected:
    string s;
    string prefijo;
    string pais;
    string editorial;
    string secuencia;
    string digitoV;
    string nuevo = "";
friend class Book;
friend class List;
};

#endif // ISBN_H
