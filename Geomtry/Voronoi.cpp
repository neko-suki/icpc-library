//accepted by rose 2160,rose 1213
//cut pos is depend on whether input polygon is clockwise or cunterclock wise
//ortho?gical line de cut
#include<iostream>
#include<complex>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
const double eps = 1e-10;

#define RIGHT 1
#define LEFT -1

typedef complex<double> P;
typedef vector<P> Polygon;
typedef pair<P,P> Line;

double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

P intersection_ll(P a1,P a2,P b1,P b2){
  P a=a2-a1,b=b2-b1;
  return a1+a*cross(b,b1-a1)/cross(b,a);
}


int ccw(P a,P b){
  if ( cross(a,b)<0)return RIGHT;
  else if ( cross(a,b)>0)return LEFT;
  return 2;
}

vector<P> Convex_Cut(Polygon in,int n,P a1,P a2,int cutpos){
  vector<P> ret;
  rep(i,n){
    P now = in[i],next=in[(i+1)%n];
    if( ccw(a1-a2,now-a2)==cutpos)ret.push_back(now);
    if ( ccw(a1-a2,now-a1)*ccw(a1-a2,next-a2)<0)
      ret.push_back(intersection_ll(a1,a2,now,next));
  }
  return ret;
}

//cutpos ha mondai izon. which side will remain
Line make_line(P ori,P b,int cutpos){
  P tmp=(ori+b);
  tmp.real()/=2;tmp.imag()/=2;
  P ret=b-tmp;
  swap(ret.real(),ret.imag());
  ret.real()*=-1;
  if ( ccw(ret,ori-tmp)!= cutpos)return make_pair(tmp,ret+tmp);
  return make_pair(ret+tmp,tmp);
}


/*tool for rose 2160

double Polygon_Area(vector<P> a,int n){
  double sum=0;
  rep(i,n){
    sum+=(a[i%n].real()-a[(i+1)%n].real())*(a[i%n].imag()+a[(i+1)%n].imag());
  }
  if( sum<0)sum*=-1;
  return sum/2;
}


void solve(int n,int m,Polygon in,vector<P> CutLine){
  vector<Line> ver;
  rep(i,CutLine.size())
    if ( i == m)continue;
    else ver.push_back(make_line(CutLine[m],CutLine[i],LEFT));

  rep(i,ver.size())
    in=Convex_Cut(in,in.size(),ver[i].first,ver[i].second,LEFT);

  printf("%.4lf\n",Polygon_Area(in,in.size()));
}

main(){
  int n,m;
  while(cin>>n>>m&&n){
    Polygon a;
    vector<P> CutPoint;
    rep(i,n){
      P tmp;cin>>tmp.real()>>tmp.imag();a.push_back(tmp);
    }
    rep(i,m){
      P tmp;
      cin>>tmp.real()>>tmp.imag();
      CutPoint.push_back(tmp);
    }

    rep(i,m)
      solve(n,i,a,CutPoint);

  }
}

*/
