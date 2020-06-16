#include "inc/RSA.h"

template <class T>
void displayC(vector<T> mc){
  T s=mc.size();
  for(int i=0; i<s; i++)
    cout<<mc[i]<<" ";
  cout<<endl;
}

int main(){
  string mensaje="hola que tal 6532";
	RSA<ll> emisor; 
  vector<ll> m; //copiar el vector para descifrar

  // Cifrado
  // m=emisor.cifrado(mensaje); displayC<ll>(m);

  // Descifrado
  // string mc=emisor.descifrado(m); cout<<mc<<endl;
  return 0;
}