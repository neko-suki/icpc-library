//凸な多角形の切断

//aoj 1283
//uva 10406
#include<iostream>
#include<complex>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define EPS 1e-10

#define RIGHT 1
#define LEFT  -1

typedef complex<double> P;

double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

P intersection_ll(P a1,P a2,P b1,P b2){
  P a=a2-a1,b=b2-b1;
  return a1 + a*cross(b,b1-a1)/cross(b,a);
}



int ccw(P a,P b){
  if (cross(a,b)<0 )return RIGHT;
  else if ( cross(a,b)>0)return LEFT;
  return 2;
}

//ただし辺が直線に含まれる場合、端点が直線上にある場合は対処が必要。
//辺を平行移動させるときは９０度回転させて
vector<P> Convex_Cut(P *in,int n, P a1,P a2){
  vector<P> ret;
  rep(i,n){
    P now = in[i],next=in[(i+1)%n];
    if ( ccw(a1-a2,now-a2)==RIGHT)ret.push_back(now);
    if ( ccw(a1-a2,now-a2)*ccw(a1-a2,next-a2)< 0 )
      ret.push_back( intersection_ll(a1,a2,now,next));
  }
  
  return ret;
}
main(){

}
