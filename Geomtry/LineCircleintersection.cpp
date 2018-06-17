//0,0を始点としてdx,dy方向に伸びる線分と(rx,ry)を中心とする半径rの円の交点を求める時に使う。
//dxt+rx, dyt+ryが答えになる。tは必要に応じて2つ求めたりしてもいい。
//accepted uva659, rose 2045
//pair<double,double> check(double dx,double dy,double rx,double ry,double r){
double check(double dx,double dy,double rx,double ry,double r){
  double a=(dx*dx+dy*dy),b=-2*rx*dx-2*ry*dy,c=rx*rx+ry*ry-r*r;
  double D=b*b-4*a*c;
  if (D < 0)return -1;
  else return (-b-sqrt(D))/(2*a);
}
