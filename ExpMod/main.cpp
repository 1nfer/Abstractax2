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