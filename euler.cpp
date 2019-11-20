#include<iostream>
#include <fstream>
#include <sstream>
#include <math.h> 
#include<cmath>

using namespace std;

const double K = 100;
const double M = 2;
const double LAMBDA = 1;
const double DeltaT = 0.01;

double f0(double t, double y0, double y1); // derivada de y0
double f1(double t, double y0, double y1); // derivada de y1
double euler(double y, double t, double h);    
    
double f0(double y1)
{
  return y1;
}

double f1(double y0)
{
  return (-K/M)*pow(y0, LAMBDA);
}
void euler(double t, double h, double &y0, double &y1)
{
     y1=y1+h*f1(y0);
     y0=y0+h*f0(y1);
}
int main()
{
  string nombre_txt="datosE.dat";
  ofstream file;
  file.open(nombre_txt.c_str());
  double x, v;
  x = 1;
  v = 0;
    for(int i=0; i<=1000;i++)
    {
      file<<i<<" "<<x<<" "<<v<<"\n";
      euler(i,DeltaT,x,v);
    }
   file.close();
   return 0;
}