//Line Line intersection

//accepter by UVa609
#include<iostream>
#include<complex>
using namespace std;
#define EPS 0
#define EQ(a,b) abs(a-b) < EPS
typedef complex<double> P;
//外積
double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}
// a1,a2を通る直線とb1,b2を通る直線の交差判定

bool is_intersect_ll(P a1,P a2,P b1,P b2){
  return !EQ( cross(a1-a2,b1-b2),0.0);
}
// a1,a2を通る直線とb1,b2を通る直線の交点計算
P intersection_ll(P a1,P a2,P b1,P b2){
  P a= a2-a1,b=b2-b1;
  return a1+ a*cross(b,b1-a1)/cross(b,a);
}


main(){
  
}
