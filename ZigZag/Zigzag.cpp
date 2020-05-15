#include "inc/Zigzag.h"

Zigzag::Zigzag(int n){
 clave=n;
}

string Zigzag::cifrado(string M){
  string MC; int n=M.size();
  for(int fil=0; fil < clave; fil++){
    for(int col=0; col+fil < n; col+=2*clave-2){
      MC += M[col+fil];
      if(fil!=0 && fil!=clave-1 && col+ 2*clave-2 -fil<n)
        MC += M[col+ 2*clave-2 -fil];
    }
  }
  return MC;
}

string Zigzag::descifrado(string MC){
  string M; int n=MC.size(), pos=0;
  for(int i = 0; i<n; i++)
    M += ' ';

  for(int fil=0; fil < clave; fil++){
    for(int col=0; col+fil < n; col+=2*clave-2){
      M[col+fil] = MC[pos++];
      if(fil!=0 && fil!=clave-1 && col+ 2*clave-2 -fil<n)
        M[col+ 2*(clave-1) -fil]=MC[pos++];
    }
  }
  return M;
}