#include "inc/Vigenere.h"

string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
int a=alfabeto.size();

Vigenere::Vigenere(string k){clave=k;}

void Vigenere::cifrado(){
  string m = readFile(); int s=m.size(), c=clave.size();
  for(int i=0,j=i; i<s; i++, j++){
    if(j==c) j=0;
    int pos = alfabeto.find(m[i]) + alfabeto.find(clave[j]);
    if(pos>a-1)
      m[i] = alfabeto[mod(pos,a)];
    else
      m[i] = alfabeto[pos];
  }
  writeFile(m);
}

void Vigenere::descifrado(){
  string mc=readFile(); int s=mc.size(), c=clave.size();
  for(int i=0,j=i; i<s; i++, j++){
    if(j==c) j=0;
    int pos = alfabeto.find(mc[i]) - alfabeto.find(clave[j]);
    if(pos<0)
      mc[i] = alfabeto[mod(pos,a)];
    else
      mc[i] = alfabeto[pos];
  }
  writeFile(mc);
}
