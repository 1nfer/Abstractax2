#include "inc/Funciones.h"

string readFile(){
  string mensaje;
  ifstream archivo; archivo.open("mensaje.txt");
  while (!archivo.eof())
    getline(archivo,mensaje);
  archivo.close();
  return mensaje;
}

void writeFile(string mensaje){
  ofstream archivo;
  archivo.open("mensaje.txt");
  archivo << mensaje;
  archivo.close();
}

int mod(int a, int n){
  int q=a/n, r=a-q*n;
  if(a<0)
    r=n+r;
  return r;
}

int mcd(int m, int n){
  if(!m)
    return n;
  while(n!=m){
    if(n>m)
      n-=m;
    else
      m-=n;
  }
  return m;
}

vector<int> mcdE(int a, int b){
  vector<int> ext;
  int x0(1), x1(0);
  int y0(0), y1(1);
  int r0(a), r1(b);
	int q,r,x,y;
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
  ext.push_back(x);
  ext.push_back(y);

  return ext;
}