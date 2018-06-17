//円のライブラリ
//円の交点,円の交差判定など。
//



//accepted by Viva confetti (ZOJ,POJ,Archive)
//まず円の座標をa,b,半径をr1,r2とおく。
//そしてa,bを結ぶ直線と円の交点同士を結んだ直線の交点の座標を(x,y)とする。
//さらに、(x,y)から交点までの距離をn,(x,y)からaまでの距離をl,(x,y)からbまでの距離をmとおく。
//最後にa,b間の距離をdとおく。
//m=d-l(l+m=d)と三平方の定理を用いるとlの長さが求まる。
//lがも止まったら、次はそこからx,yのいちが求まる
//最後にx,yからp,qという座標を、三角形の相似を使って求める。
//参考　http://www.ipsj.or.jp/07editj/promenade/4406.pdf

pair<P,P> CC_intersection(P a,P b,double r1,double r2){//円と円の交点
  double l,m,n;
  double d = abs(a-b);
  double x,y;
  double p,q;
  l=(d*d-r2*r2+r1*r1)/(2*d);
  
  x=a.real()+(b.real()-a.real())*l/d;
  y=a.imag()+(b.imag()-a.imag())*l/d;
  
  n=sqrt(r1*r1-l*l);
  
  p=(b.imag()-a.imag())/d*n;
  q=(b.real()-a.real())/d*n;
  
  return mp(P(x+p,y-q),P(x-p,y+q));
}

//0:a include b
//1:b include a
//2:intersected
//3:same
//4:far away
// r1 >= r2
//accepted by Viva confetti (ZOJ,POJ,Archive)
//円と円が接するときの判定は
//  if (fabs(r1+r2-d) < eps)return 5;
//をreturn 4の前辺りにいれるとうまくい茎がする(malfatti circle aoj 1301

int is_intersected_circle(P a,P b,double r1,double r2){
  double d = abs(a-b);
  if (d<eps && abs(r1-r2)<eps)return 3;
  if (d+r2 < r1)return 0;
  if (d+r1 < r2)return 1;
  if (d > r1+r2)return 4;
  return 2;
}
