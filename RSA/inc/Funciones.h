#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <bitset>
using namespace std;
using ll=unsigned long long;

template <class T>
T mod(T a, T n){
  T q=a/n, r=a-q*n;
  if(a<0)
    r=n+r;
  return r;
}

template <class T>
T mcd(T a, T b){
  T r=mod(a,b);
   while(r!=0){
      if(r>b/2)
         r=b-r;
      a=b;
      b=r;
      r=mod(a,b);
   }
   return b;
}

template <class T>
vector<T> mcdE(T a, T b){
  vector<T> extendido;
  T s1=1, s2=0;
  T t1=0, t2=1;
  T r1=a, r2=b;
	T q,r,s,t;
	while(r2){
		q=r1/r2;
    
		r=r1-q*r2;
		r1=r2;
		r2=r;

		s=s1-q*s2;
		s1=s2;
		s2=s;

		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	s=s1;
  t=t1;

  extendido.push_back(r);
  extendido.push_back(s);
  extendido.push_back(t);
  return extendido;
}

template <class T>
T exp_Mod(T a,T b,T n){
  T res=1;
  T x=mod<T>(a,n);
  b=mod<T>(b,n);
  while(b>0){
    if(mod<T>(b,(T)2))
      res=mod<T>(res*x,n);
    x=mod<T>(x*x,n);
    b=b/2;
  }
  return res;
}

#define n 9999999
#define t (ll)(n-3)/2 + 1

template <class T>
vector<T> criba(){
  vector<T> primos;
  bitset<t> bset;
	T i, j;
	for (i=0; i*i <= n; i++){
		if (!bset.test(i)){
			for (j=i+1; (2*j+1)*(2*i+3)<=n; j++)
				bset.set(((2*j+1)*(2*i+3)-3)/2);
		}
	}

	primos.push_back(2);
	for (i=1, j=0; j<t; j++){
		if (!bset.test(j))
			primos.push_back(2*j+3);
	}
  // mostrar la criba
  // T s=primos.size();
  // for(i=0; i<s; i++)
  //   cout<<primos[i]<<" ";
  return primos;
}

template<class T>
vector<T> genPrimo(){
  vector<T> primos=criba<T>(), claves;
  T s=primos.size();
  claves.push_back(primos[s-1]);
  claves.push_back(primos[s-2]);
  return claves;
}