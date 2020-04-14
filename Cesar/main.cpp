#include <iostream>
#include "inc/Cesar.h"

int main(){
  Cesar emisor(44);
  Cesar receptor(44);
  string mensaje;
  getline(cin, mensaje);

  string mC = emisor.cifrado(mensaje); cout<<mC<<endl;
  string mD = receptor.descifrado(mC); cout<<mD<<endl;

  return 0;
}