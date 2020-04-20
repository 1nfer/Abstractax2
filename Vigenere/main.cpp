#include <iostream>
#include "inc/Vigenere.h"
using namespace std;

void menu(){
  cout<<"1: Cifrar"<<endl<<"2: Descifrar"<<endl;
  int i; cin>>i;

  string mensaje=readFile(); int s=mensaje.size();

  cin.ignore();
  cout<<"Clave: ";
  string clave;
  getline(cin,clave);
  int c=clave.size();
  while(c>s){
    cout<<"La longitud de la clave debe ser menor o igual al del mensaje"<<endl;
    cout<<"Ingresa una nueva clave: "<<endl;
    getline(cin,clave); c=clave.size();
  }

  if(i==1){
    Vigenere emisor(clave);
    emisor.cifrado();
  }
  if(i==2){
    Vigenere receptor(clave);
    receptor.descifrado();
  }
}

int main(){
  menu();
  return 0;
}