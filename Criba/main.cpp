#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

using ll=unsigned long long;

#define n 10
#define t (ll)(n-3)/2 + 1

template <class T>
vector<T> criba(){
  vector<T> primos;
  bitset<t> bset; cout<<bset<<endl;
	T i, j;
	for (i=0; i*i <= n; i++){
		if (!bset.test(i)){
			for (j=i+1; (2*j+1)*(2*i+3)<=n; j++){
        int b=((2*j+1)*(2*i+3)-3)/2;
				bset.set(b);
        cout<<bset<<" "<<endl;
      }
		}
	}

	primos.push_back(2);
	for (j=0; j<t; j++){
		if (!bset.test(j)){
			primos.push_back(2*j+3);
    }
	}

  T s=primos.size();
  for(i=0; i<s; i++)
    cout<<primos[i]<<" ";
  return primos;
}

int main(){
  vector<int>a=criba<int>();
}