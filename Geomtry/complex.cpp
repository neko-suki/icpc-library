//complex型

//last update 4/28
#include<iostream>
#include<complex>
#include<cmath>
using namespace std;

typedef complex<double> P;

#define EPS (1e-10)
#define EQ(a,b) ( fabs((a)-(b)) < EPS)
#define EQV(a,b) ( EQ( (a).real(),(b).rea()) && EQ((a).imag(),(b).imag()))
#define D distance_ls_p

namespace std{//complexをmapに入れる際に定義する
  bool operator<(const P &a,const P &b){
    if ( a.real() != b.real())return a.real()<b.real();
    else if ( a.imag()!=b.imag())return a.imag()<b.imag();
    return false;
  }
}


//Dot product 内積
//accepted by rose2003
//accepted by uva 10709
double dot(P a,P b){
  return ( a.real()*b.real() + a.imag()*b.imag());
}

// cross product
// accepted by rose2003
//  uva 273,191,476,10709
double cross(P a,P b){
  return ( a.real()*b.imag() - a.imag()*b.real());
}
//二直線の直行判定
//accepted by 
//
bool is_orthogonal(P a1,P a2,P b1,P b2){
  return EQ( dot(a1-a2,b1-b2) ,0.0);
}
//二直線の平行判定
//accepted by uva 10709
//
bool is_parallel(P a1,P a2,P b1,P b2){
  return EQ( cross(a1-a2,b1-b2),0.0);
}

//点a,bを通る直線と点cとの距離
//accepted by uva 10709
//
double distance_l_p(P a,P b,P c){
  return abs( cross(b-a,c-a))/abs(b-a);
}
//点a,bを端点とする線分と点cとの距離
//accepted by 10709
//
double distance_ls_p(P a,P b,P c){
  if (dot(b-a,c-a) < EPS)return abs(c-a);
  if (dot(a-b,c-b) < EPS)return abs(c-b);
  return abs( cross(b-a,c-a))/abs(b-a);
}
//a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
//accepted by
//uva 273,191,10709
//rose 2003
//memo 
//<=EPSにすると４点が一直線
bool is_intersected_ls(P a1,P a2,P b1,P b2){
  if ( is_point_online(a1,a2,b1))return true;
  if ( is_point_online(a1,a2,b2))return true;
  if ( is_point_online(b1,b2,a1))return true;
  if ( is_point_online(b1,b2,a2))return true;
  if (  ( cross(a2-a1,b1-a1) * cross(a2-a1,b2-a1)<EPS ) && //-EPS
	( cross(b2-b1,a1-b1)*cross(b2-b1,a2-b1)<EPS))return true;
  else return false;
}

//点ｃが線分ABの上にあるかどうか,三角不等式で求める
//accepted by 191,476
//            rose2003
bool is_point_online(P a,P b,P c){
  return ( abs(a-c)+abs(b-c) < abs(a-b)+EPS);
}


//x,y軸に平行な長方形の交差判定
bool is_rectangle_intersect(double *left,double *top,double *right,double *bottom){
  if ( left[0]  <=right[1] && top[0] >=bottom[1] && 
       right[0] >=left[1]  && bottom[0] <=top[1])return true;
  else return false;
}


/*
bool is_point_online(complex<int> a1,complex<int> b1,complex<int> c1){
  complex<double> a,b,c;
  a=a1;b=b1;c=c1;
  return ( abs(a-c)+abs(b-c) < abs(a-b)+0.0000001);
}
*/

//線分と線分の最短距離を求める
//accepted by uva 10709
//rose 1156?
double distance_ss_p(Point a,Point b,Point c,Point d){
  return min(  min( D(a,b,c),D(a,b,d)),min(D(c,d,a),D(c,d,b)));
}


//a1,a2を端点とする線分とb1,b2を端点とする線分の交点を求める。
//accepted by  uva 609
//            rose2003
P intersection_ls(P a1,P a2,P b1,P b2){
  P b = b2-b1;
  double d1=abs(cross(b,a1-b1));//
  double d2=abs(cross(b,a2-b1));
  double t = d1/(d1+d2);//パラメータ t:1-t = d1:d2
  return a1+(a2-a1)*t;
}
//時計回りかどうかを調べる。
//accepted by 191,476,477,478,
int ccw(P a,P b){
  if ( cross(a,b)<0)return 1;//aとbのなす角が負
  else if (cross(a,b)>0)return -1;//a,bのなす角が正
  else return 2;
}
double angle(P a,P b){
  double costheta = dot(a,b)/( abs(a)*abs(b));
  double arccos = acos(costheta);
  //cout << costheta << " " << arccos << endl;
  //cout << a.real() << " "<< a.imag() << " " << b.real() << " " <<
  // b.imag() << endl;
  return arccos * 180/acos(-1);
}


//線分と円の交差判定。
bool is_intersect_cl(P a,P b,P circle,double radius){
  bool flag1 = abs(a-circle) <=radius ?1:0;//点aが円内にあるかどうか
  bool flag2 = abs(b-circle) <=radius ?1:0;//点bが円内にあるかどうか
  
  if ( flag1 ==  flag2){
    if ( flag1 == 0){//両方外側の時は,線分と円の中心点の最短距離と半径の比較
      if ( distance_ls_p(a,b,circle) <= radius)return true;
    }
    else if ( flag1 == 1){//内側の時
      return false;
    }
  }else {//片方が内側、もう片方が外側の時。
    return true;
  }
  return false;
}

/*
内接円の中心点は
三角形の書くの二等分線の交点
 */

main(){

}
