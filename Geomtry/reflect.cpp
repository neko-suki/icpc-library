//symmetric point あるいはベクトルの反射
//AOJ 1171
double dot(P a,P b){
  return a.real()*b.real()+a.imag()*b.imag();
}

//線分oとpに対して、ｑの線対称な点を求める。
//まずoを原点として、NベクトルとLベクトルを求めてせいきかする。
//その後にLのN方向に垂直成分を求める。あとはその2倍��Lをすると、正規化されたRベクトルが求める。
//後は原点を足して、Lの元の大きさ倍してあげればいい。

P symmetric_point(P o,P p,P q){
  P N=p-o,L=q-o;
  double t = abs(L);
  N/=abs(N);
  L/=abs(L);
  double prepL = dot(N,L);//theta element of vector L against N (|L|=|N|=1
  double d=2*prepL;
  P r(d*N - L);//R vector symmetric point of L
  return o+t*r;
}
