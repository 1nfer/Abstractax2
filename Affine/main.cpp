#include <iostream>
#include <string>
#include "inc/Affine.h"
using namespace std;

void menu(){
  int op;
  string mensaje;
  do{
    cout<<"----MENU----"<<endl;
    cout<<"1. Cifrar"<<endl;
    cout<<"2. Descifrar"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Opcion: "; cin>>op; cout<<endl;
    switch (op){
    case 1:{
      cout<<"Claves usadas para el cifrado:"<<endl;
      Affine emisor;
      emisor.cifrado();
      cout<<endl;
      }
      break;
    
    case 2:
      int A, B;
      cout<<"Ingrese las claves:"<<endl;
      cout<<"A: "; cin>>A;
      cout<<"B: "; cin>>B;
      Affine receptor(A,B);
      receptor.descifrado();
      cout<<"Mensaje Descifrado:"<<endl;
      break;
    }
  } while (op!=3);
  
}
  
int main(){
  menu();
  return 0;
}