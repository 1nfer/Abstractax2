#include <iostream>
#include <vector>
using namespace std;

template <class T>
T mod(T a, T b){
  T q=a/b, r=a-q*b;
  if(r<0)
    r+=b; 
  return r;
}

template <class T>
vector<T> Egcd(T a, T b){
  vector<T> ext;
  T x0(1), x1(0);
  T y0(0), y1(1);
  T r0(a), r1(b);
	T q,r,x,y;
	while(r1!=0){
		q=r0/r1;

		r=r0-q*r1;
		r0=r1;
		r1=r;

		x=x0-q*x1;
		x0=x1;
		x1=x;

		y=y0-q*y1;
		y0=y1;
		y1=y;
	}
	x=x0;
  y=y0;

  ext.push_back(r);
  ext.push_back(mod(x,b));
  ext.push_back(mod(y,b));

  return ext;
}

int main(){
	vector<int>e=Egcd<int>(140,9);
	int a=e[1]; cout<<a;
}
X0 = 2*140*2+3*180*3+1*315*3+(-1mod1260)*252*3 (mod 1260)
