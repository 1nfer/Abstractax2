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
   while(r!=0){ // cout<<a<<" "<<b<<" "<<r<<endl;
      a=b;
      b=r;
      r=modulo(a,b);
   }
   return b;
}

ZZ segundo(ZZ a, ZZ b){
   ZZ r=modulo(a,b);
   while(r!=0){ // cout<<a<<" "<<b<<" "<<r<<endl;
      if(r>b/2)
         r=b-r;
      a=b;
      b=r;
      r=modulo(a,b);
   }
   return b;
}

ZZ tercero(ZZ a, ZZ b){ // cout<<a<<" "<<b<<" "<<modulo(a,b)<<endl;
   if(b==0) return a;
   return tercero(b, modulo(a,b));
}

ZZ cuarto(ZZ a, ZZ b){ // cout<<a<<" "<<b<<" "<<modulo(a,b)<<endl;
   if(abs(b)>abs(a)) return cuarto(b,a);
   if(b==0) return a;
   if(((a ^ 1) == a + 1) && ((b ^ 1) == b + 1)) return 2*cuarto(a>>1,b>>1);
   if(((a ^ 1) == a + 1) && ((b ^ 1) != b + 1)) return cuarto(a>>1,b);
   if(((a ^ 1) != a + 1) && ((b ^ 1) != b + 1)) return cuarto(a,b>>1);
   return cuarto((abs(a)-abs(b))>>1,b);
}

ZZ quinto(ZZ x, ZZ y){
   ZZ g(1);
   while(modulo(x,(ZZ)2)==0 && modulo(y,(ZZ)2)==0){ // cout<<x<<" "<<y<<" "<<g<<endl;
      x/=2;
      y/=2;
      g=2*g;
   } // cout<<"while 2: "<<endl;
   while(x!=0){ // cout<<"WHILE: "<<x<<" "<<y<<" "<<g<<" "<<endl;
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
   while(n!=m){ // cout<<m<<" "<<n<<endl;
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
