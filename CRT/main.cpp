#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;

int modE(int a, int b){
  int q=a/b, r=a-q*b;
  if(r<0)
    r+=b; 
  return r;
}

vector<ZZ> Egcd(ZZ a,ZZ b){
  vector<ZZ> ext;
  ZZ r1=a;
  ZZ r2=b;
  ZZ s1(1),s2(0),t1(0),t2(1),q,r,s,t;
  while(r2>0){
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
  ext.push_back(modE(r,b));
  ext.push_back(modE(s1,b));
  ext.push_back(modE(t1,b));
  return ext;
}

ZZ CRT(const vector<ZZ> &a, const vector<ZZ> &m, long t){
  long i; vector<ZZ> e;
  ZZ P {1}, n, x {0}, u;
  for (ZZ d:m) P *= d;
  for (i=0; i<t; ++i){
    n = P / m[i];
    e = Egcd(n,m[i]);
    u = e[1];
    x += n * u * a[i];
    modE(x,P);
  }
  return x;
}