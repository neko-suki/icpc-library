//２円の共通外接線,共通内接線を求める。
//

#include<iostream>
#include<cmath>
#include<complex>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define mp         make_pair
#define pb         push_back

typedef complex<double> P;
typedef pair<P,P>       Line;
const double eps = 1e-10;

double distance_l_p(P a,P b,P c);
double cross(P a,P b);

typedef struct{P p;double r;}C;
//外接線
//円の中心点を結ぶ点と,接線に平行な線で２つの円の中心を通る線からなる三角形を考える。
//2点間の距離と円の半径の関係からcos(theta)=(r0-r1)/(2点間の距離)になる。
//あとは2点間を結んだ線分をこのtheta分だけ回転させる。
pair<Line,Line> external_common_tangent(C a,C b){
  if (a.r < b.r)swap(a,b);
  double theta=acos((a.r-b.r)/abs(a.p-b.p));
  double costheta=cos(theta),sintheta=sin(theta);

  Line ret[2];
  rep(i,2){
    P v = b.p-a.p;
    P va,vb;//vector for circle a,b
    va.real()=v.real()*costheta-v.imag()*sintheta;
    va.imag()=v.real()*sintheta+v.imag()*costheta;
    va/=abs(va);
    vb=va;
    va*=a.r;
    vb*=b.r;

    va+=a.p;
    vb+=b.p;
    
 
    ret[i]=mp(va,vb);
    sintheta*=-1;
  }

  return mp(ret[0],ret[1]);
}


//共通内接線
//二つの円が交差するときは存在しない
pair<Line,Line> internal_common_tangent(C a,C b){
  double theta=acos((a.r+b.r)/abs(a.p-b.p));

  
  if (-eps<theta && theta<eps){
    P v=b.p-a.p;
    Line ret;

    swap(v.real(),v.imag());
    v.real()*=-1;
    ret.first=(a.p+b.p)/2.;
    ret.second=ret.first+v;

    
    return mp(ret,ret);
  }

  double costheta=cos(theta),sintheta=sin(theta);
  Line ret[2];
  rep(i,2){
    P v = b.p-a.p;
    P va,vb;//vector for circle a,b
    va.real()=v.real()*costheta-v.imag()*sintheta;
    va.imag()=v.real()*sintheta+v.imag()*costheta;
    va/=abs(va);
    vb=va;
    va*=a.r;
    vb*=-b.r;

    va+=a.p;
    vb+=b.p;
    

    ret[i]=mp(va,vb);
    sintheta*=-1;
  }
  return mp(ret[0],ret[1]);
}


double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

double distance_l_p(P a,P b,P c){
  return abs(cross(b-a,c-a))/abs(b-a);
}

bool checkdist(C a,Line b,double m){
  double dist =distance_l_p(b.first,b.second,a.p);
  //if (dist+eps < a.r || dist-eps > a.r+m)return false;
  //return true;
  if (a.r-eps<=dist && dist <= a.r+m+eps)return true;
  return false;
}

vector<Line> find_all(vector<C> &in){
  vector<Line> ret;
  rep(i,in.size()){
    REP(j,i+1,in.size()){
      if (abs(in[i].p-in[j].p)<eps)continue;
      pair<Line,Line> tmp1=external_common_tangent(in[i],in[j]);
      
      ret.pb(tmp1.first);
      ret.pb(tmp1.second);
      if (abs(in[i].p-in[j].p)-in[i].r-in[j].r>-eps){
	tmp1=internal_common_tangent(in[i],in[j]);
      
	ret.pb(tmp1.first);
	ret.pb(tmp1.second);
      }
    }
  }
  return ret;
}

int solve(vector<C> a,vector<double> m){
  int ans = 1;
  vector<C> check;
  rep(i,a.size()){
    check.pb((C){a[i].p,a[i].r});
    check.pb((C){a[i].p,a[i].r+m[i]});
  }

  vector<Line> all=find_all(check);
  
  
  

  rep(i,all.size()){
    int tmp = 0;
    rep(j,a.size()){
      if (checkdist(a[j],all[i],m[j]))tmp++;
    }
    ans=max(tmp,ans);
  }
  return ans;
}


main(){
  int n;
  while(cin>>n && n){
    vector<C> in;
    vector<double> M;
    rep(i,n){
      double x,y,r,m;cin>>x>>y>>r>>m;
      in.pb((C){P(x,y),r});
      M.pb(m);
    }
    cout << solve(in,M) << endl;
  }
}
