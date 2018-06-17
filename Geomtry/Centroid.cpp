//多角形の重心を求める
//ただしconter clock wiseでしかverify していない。
//accepted at uva 10002,AOJ 1292
//reference http://local.wasp.uwa.edu.au/‾pbourke/geometry/polyarea/

P compute_centeroid(vector<P> &in,int n){
  double cx=0,cy=0;//center
  double a=0;//area of polygon
  rep(i,n){
    double cr=cross(in[i],in[(i+1)%n]);
    a+=cr;
    cx+=(in[i].real()+in[(i+1)%n].real())*cr;
    cy+=(in[i].imag()+in[(i+1)%n].imag())*cr;
  }
  a/=2.0;
  //  if (a < 0)a*=-1;//may be don't need
  cx/=(6.0*a);
  cy/=(6.0*a);
  return P(cx,cy);
}
