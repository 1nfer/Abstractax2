#include <iostream>
#include <string>
#include "inc/Zigzag.h"
using namespace std;

int main(){
  Zigzag emisor(4);
  Zigzag receptor(4);
  string mensaje;
  getline(cin, mensaje);

  string mC = emisor.cifrado(mensaje); cout<<mC<<endl;
  string mD = receptor.descifrado(mC); cout<<mD<<endl;
  
  return 0;
}