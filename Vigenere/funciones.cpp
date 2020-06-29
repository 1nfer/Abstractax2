#include "inc/Funciones.h"

string readFile(){
  string mensaje;
  ifstream archivo; archivo.open("mensaje.txt");
  while (!archivo.eof())
    getline(archivo,mensaje);
  archivo.close();
  return mensaje;
}

void writeFile(string mensaje){
  ofstream archivo;
  archivo.open("mensaje.txt");
  archivo << mensaje;
  archivo.close();
}

int mod(int a, int b){
  int q=a/b, r=a-q*b;
  if(r<0)
    r+=b;
  return r;
}