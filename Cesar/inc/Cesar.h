#include <string>
using namespace std;

class Cesar{
  int clave;
public:
  Cesar(int);
  string cifrado(string);
  string descifrado(string);
};