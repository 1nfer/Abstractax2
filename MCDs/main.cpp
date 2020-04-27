#include <NTL/ZZ.h>
#include "funciones.h"
using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ n){
  ZZ q=a/n, r=a-q*n;
  if(a<0)
    r=n+r;
  return r;
}

ZZ primer(ZZ a, ZZ b){
   ZZ r=modulo(a,b);
   while(r!=0){
      a=b;
      b=r;
      r=modulo(a,b);
   }
   return b;
}

ZZ segundo(ZZ a, ZZ b){
   ZZ r=modulo(a,b);
   while(r!=0){
      if(r>b/2)
         r=b-r;
      a=b;
      b=r;
      r=modulo(a,b);
   }
   return b;
}

ZZ tercero(ZZ a, ZZ b){
   if(b==0) return a;
   return tercero(b, modulo(a,b));
}

ZZ cuarto(ZZ a, ZZ b){
   if(abs(b)>abs(a)) return cuarto(b,a);
   if(b==0) return a;
   if(modulo(a,(ZZ)2)==0 && modulo(b,(ZZ)2)==0) return 2*cuarto(a/2,b/2);
   if(modulo(a,(ZZ)2)==0 && modulo(b,(ZZ)2)==1) return cuarto(a/2,b);
   if(modulo(a,(ZZ)2)==1 && modulo(b,(ZZ)2)==0) return cuarto(a,b/2);
   return cuarto((abs(a)-abs(b))/2,b);
}

ZZ quinto(ZZ x, ZZ y){
   ZZ g(1);
   while(modulo(x,(ZZ)2)==0 && modulo(y,(ZZ)2)==0){
      x/=2;
      y/=2;
      g=2*g;
   }
   while(x!=0){
      while(modulo(x,(ZZ)2)==0) x/=2;
      while(modulo(y,(ZZ)2)==0) y/=2;
      ZZ t=abs(x-y)/2;
      if(x>=y) x=t;
      else y=t;
   }
   return g*y;
}

ZZ sexto(ZZ m, ZZ n){
   if(m==0)
      return n;
   while(n!=m){
      if(n>m)
         n-=m;
      else
         m-=n;
   }
   return m;
}

int main(){
   ZZ a, b; cin >> a; cin>> b;
   // cout<<primer(a,b)<<endl; 
   // cout<<segundo(a,b)<<endl;
   // cout<<tercero(a,b)<<endl;
   // cout<<cuarto(a,b)<<endl;
   // cout<<quinto(a,b)<<endl;
   // cout<<sexto(a,b)<<endl;

   auto t1 = std::chrono::high_resolution_clock::now();
   primer(a,b);
   auto t2 = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
   cout << duration<<endl;

   t1 = std::chrono::high_resolution_clock::now();
   segundo(a,b);
   t2 = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
   cout << duration<<endl;

   t1 = std::chrono::high_resolution_clock::now();
   tercero(a,b);
   t2 = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
   cout << duration<<endl;

   t1 = std::chrono::high_resolution_clock::now();
   cuarto(a,b);
   t2 = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
   cout << duration<<endl;

   t1 = std::chrono::high_resolution_clock::now();
   quinto(a,b);
   t2 = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
   cout << duration<<endl;

   t1 = std::chrono::high_resolution_clock::now();
   sexto(a,b);
   t2 = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
   cout << duration<<endl;

   
}
