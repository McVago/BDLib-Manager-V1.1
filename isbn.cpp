#include "isbn.h"
#include <iostream>
#include <isbn.h>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;
ISBN::ISBN(){}

ISBN::ISBN(string cadena){
    int cont = 0;
    s = cadena;

    if (s.length()==13 || s.length()==10){
        prefijo = "000";
        for (unsigned int i = 0; i < s.length() ; i++){
            if (s[i] != 32 && s[i] != '-'){
                if (cont == 0){ pais = pais + s[i]; }
                if (cont == 1){ editorial = editorial + s[i]; }
                if (cont == 2){ secuencia = secuencia + s[i]; }
                if (cont == 3){ digitoV = digitoV + s[i]; }

            }
            else{
                cont = cont + 1;
            }
        }nuevo = pais + editorial + secuencia;
 }
    if (s.length()==17 || s.length()==13){
        for (unsigned int i = 0; i < s.length() ; i++){
            if (s[i] != 32 && s[i] != '-'){
                if (cont == 0){ prefijo = prefijo + s[i]; }
                if (cont == 1){ pais = pais + s[i]; }
                if (cont == 2){ editorial = editorial + s[i]; }
                if (cont == 3){ secuencia = secuencia + s[i]; }
                if (cont == 4){ digitoV = digitoV + s[i]; }
            }
            else {
                cont = cont +1; }

        }nuevo =prefijo+ pais + editorial + secuencia;
    }
    if (s.length()!=13 && s.length()!=17) { cout << "ISBN Incorrecto" << endl;}

}

bool ISBN::verificar(){
    int valorP = atoi(prefijo.c_str());
    int valorN = atoi (nuevo.c_str());
    int valorD = atoi (digitoV.c_str());

    if (valorP == 0){
        int respaldo = valorN;
        int j = 1;
        int suma = 0;
        for (int i = 8; i >= 0; i--){
            int potencia = pow(10,i);
            int solo = respaldo/potencia;
            suma = suma +(solo*j);
            respaldo = respaldo %(potencia);
            j++;
        }
        cout << suma%11 << endl;
        if (suma%11 == valorD){ cout << "Numero ISBN valido" << endl; }
        else { cout << "ERROR!  (ISBN Invalido)" << endl; }
    }
    if (valorP!= 0){
        int suma = 0;
        int sumaI = 0;
        int sumaP = 0;
        string aux1 = "";
        string aux2 = "";
        for (unsigned int i = 0; i < nuevo.length(); i++){
            if (i%2 == 1){
                aux1 = nuevo[i];
                int x = atoi(aux1.c_str());
                sumaI = sumaI + x;

            }
            else{
                aux2 = nuevo[i];
                int y = atoi(aux2.c_str());
                sumaP = sumaP + y;

            }
        } suma = (sumaI*3) + (sumaP);

        suma = suma%10;

        if (10-suma == valorD){ return true;}
        else { return false; }
    }
}
