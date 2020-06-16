#include "Funciones.h"

string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";

template <class T>
class RSA{
  T p, q, d, phiN;
public:
  T N, e;

  T gen_N(T p, T q){return p*q;};

  T gen_phiN(T p, T q){return (p-1)*(q-1);};

  T gen_e(T phiN){
    srand(time(nullptr)); 
    T e=mod((ll)rand(),phiN-1)+1;
    while(mcd(e,phiN)!=1)
      e=mod((ll)rand(),phiN-1)+1;
    return e;
  };

  T gen_d(T e,T phiN){
    vector<T> inv=mcdE(e,phiN);
    d=inv[1];
    return mod(d,phiN);
  }

  RSA(){
    vector<T> primos=genPrimo<T>();
    p=primos[0], q=primos[1];
    N=gen_N(p,q);
    phiN=gen_phiN(p,q);
    e=gen_e(phiN);
    d=gen_d(e,phiN);
    cout<<"Clave publica:"<<"<"<<e<<","<<N<<">"<<endl;
    cout<<"Clave privada:"<<"<"<<d<<","<<N<<">"<<endl;
    // cout<<p<<endl;
    // cout<<q<<endl;
    // cout<<phiN<<endl;
  }

  RSA(T, T){this->e=e; this->N=N;}

  vector<T> cifrado(string m){
    vector<T> mc; int s=m.size();
    for(int i=0; i<s; i++){
      T M = alfabeto.find(m[i]);
      T C = exp_Mod(M,e,N);
      mc.push_back(C);
    }
    return mc;
  }
  string descifrado(vector<T> mc){
    string m; int s=mc.size();
    for(int i=0; i<s; i++){
      T D = exp_Mod(mc[i],d,N);
      m+=alfabeto[D];
    }
    return m;
  }
};