#include "inc/Affine.h"

string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int a=alfabeto.size();

Affine::Affine(){
  srand(time(nullptr));
  A=(mod(rand(),a));
  while(mcd(A,a)!=1)
    A=(mod(rand(),a));
  B=(mod(rand(),a));
  cout<<"A: "<<A<<endl<<"B: "<<B<<endl;
}

Affine::Affine(int X, int Y){
  vector<int>inversa = mcdE(X,a);
  A=inversa[1]; A=mod(A,a);
  B=Y;
}

void Affine::cifrado(){
  string m=readFile(); int n=m.size();
  for(int i=0; i<n; i++){
    int f=alfabeto.find(m[i]);
    m[i]=alfabeto[mod(mod((f*A),a)+B, a)];
  }
  writeFile(m);
}

void Affine::descifrado(){
  string mc=readFile(); int n=mc.size();
  for(int i=0; i<n; i++){
    int f=alfabeto.find(mc[i]);
    mc[i]=alfabeto[mod(A*mod((f-B),a), a)];
  }
  writeFile(mc);
}