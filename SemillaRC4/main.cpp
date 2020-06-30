#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
using ll=unsigned long long;

//funcion para calcular la carga del CPU
static float CalculateCPULoad(ll idleTicks, ll totalTicks){
  static ll _previousTotalTicks = 0;
  static ll _previousIdleTicks = 0;

  ll totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
  ll idleTicksSinceLastTime = idleTicks - _previousIdleTicks;

  float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

  _previousTotalTicks = totalTicks;
  _previousIdleTicks = idleTicks;
  return ret;
}

static ll FileTimeToInt64(const FILETIME & ft){
  return (((ll)(ft.dwHighDateTime)) << 32) | ((ll)ft.dwLowDateTime);
}

// Retorna 1.0f para "CPU fully pinned", 0.0f para "CPU idle" o algo entre esos valores.
// Se necesita llamar esta funcion en intervalos regulares, porque mide la carga entre
// la anterior y actual llamada.  Retorna -1.0 por error.
float GetCPULoad(){
  FILETIME idleTime, kernelTime, userTime;
  return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
}


int main(){
  ofstream myfile;
  myfile.open("log.csv", ios::out | ios::app);

  //Un bucle para reunir datos del uso del CPU cada cuarto de segundo
  int counter = 0;
  while(counter<5){
    myfile <<GetCPULoad()*100<<"%"<<"\n";
    Sleep(250);
    counter = counter + 1;
  }
  myfile.close();
  return 0;
}