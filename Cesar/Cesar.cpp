#include "inc/Cesar.h"

int mod(int a, int b){
  int q=a/b, r=a-q*b;
  if(r<0)
    r+=b; 
  return r;
}

string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
int a=alfabeto.size();

Cesar::Cesar(int n){clave=n;}

string Cesar::cifrado(string M){
  int m = M.size();
  for(int i=0; i<m; i++){
    int pos = alfabeto.find(M[i])+clave;
    if(pos+clave > a-1)
      M[i] = alfabeto[mod(pos,a)];
  }
  return M;
}

string Cesar::descifrado(string MC){
  int m=MC.size();
  for(int i=0; i<m; i++){
    int pos=alfabeto.find(MC[i])-clave;
    if(pos-clave < 0)
      MC[i] = alfabeto[mod(pos,a)];
  }
  return MC;
}