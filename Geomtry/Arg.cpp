//complex型の角度計算
//
//

#include<iostream>
#include<cmath>
#include<complex>
using namespace std;
main(){
  complex<double> a(1,0);
  complex<double> b(1,1);
  complex<double> c(0,1);
  complex<double> d(0,-1);
  complex<double> e(-1,0);
  complex<double> f(-1,1);
  cout << arg(a) << endl;//0
  cout << arg(b) << endl;//0.785398
  cout << arg(c) <<endl;//1.5708
  cout << arg(d) << endl;//-1.5708
  cout << arg(e) << endl;//3.14159
  cout << arg(b) * 180/acos(-1) << endl;//45
  cout << (arg(f)-arg(b))*180/acos(-1) << endl;//90
  cout << (arg(b)-arg(f))*180/acos(-1)<<endl;//-90
}

