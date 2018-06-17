#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb push_back

const int N=300;
const int inf = (1<<20);
/*
struct Edge{int to,cap;double cost;int rev;};

vector<Edge> G[N];
double dist[N];
int prevv[N],preve[N];

void add_edge(int from,int to,int cap,double cost){
  G[from].pb((Edge){to,cap,cost+0,G[to].size()});
  G[to].pb((Edge){from,0,-cost+0,G[from].size()-1});
}

// flow of volume F, s to t
// if it's not posible return -1
double min_cost_flow(int n,int s,int t,int f){
  double res=0;
  while(f>0){
    fill(dist,dist+n,inf);
    dist[s]=0;
    bool update=true;
    //while(update){
    rep(k,n){
      if (!update)break;
      update=false;
      rep(i,n){
	//cout << i <<":: " << dist[i] << endl;
	if (dist[i] == inf)continue;
	rep(j,G[i].size()){
	  Edge &e=G[i][j];
	  //cout << i <<" " << e.to <<" " << dist[e.to]<<
	  //" " << dist[i]+e.cost << endl;
	  if(e.cap > 0 && dist[e.to]>(dist[i] + e.cost)){
	    //printf("%.20lf %.20lf\n",
	    //dist[e.to]-(dist[i]+e.cost),-1);
	    dist[e.to]=dist[i]+e.cost;
	    //cout << i <<" " <<dist[i]<<" " << dist[i]+e.cost<<
	    //" " << dist[e.to] << endl;
	    
	    prevv[e.to]=i;
	    preve[e.to]=j;
	    update=true;
	  }
	}
      }
      //rep(i,n)cout << dist[i]<<" ";cout << endl;
    }
    
    
    if (dist[t] == inf)return -1;

    int d=f;
    for(int v=t;v != s;v = prevv[v]){
      d=min(d,G[prevv[v]][preve[v]].cap);
    }
    f-=d;
    res+=d*dist[t];
    for(int v=t;v != s;v = prevv[v]){
      Edge &e=G[prevv[v]][preve[v]];
      e.cap-=d;
      G[v][e.rev].cap+=d;
    }
  }
  return res;
}
*/

typedef pair<double,int> P;

struct Edge{int to,cap;double cost;int rev;};
vector<Edge> G[N];
double h[N];
double dist[N];
int prevv[N],preve[N];

void add_edge(int from,int to,int cap,double cost){
  G[from].pb((Edge){to,cap,cost+0,G[to].size()});
  G[to].pb((Edge){from,0,-cost+0,G[from].size()-1});
}

// flow of volume F, s to t
// if it's not posible return -1
double min_cost_flow(int n,int s,int t,int f){
  double res=0;
  fill(h,h+n,0);
  while(f>0){
    priority_queue<P,vector<P>,greater<P> >que;
    fill(dist,dist+n,inf);
    dist[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
      P p=que.top();que.pop();
      //cout << p.first <<" " << p.second << endl;
      int v=p.second;
      if (dist[v] < p.first)continue;
      rep(i,G[v].size()){
	Edge &e=G[v][i];
	if (e.cap > 0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
	  dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
	  prevv[e.to]=v;
	  preve[e.to]=i;
	  que.push(P(dist[e.to],e.to));
	}
      }
    }

    
    if (dist[t] == inf)return -1;

    for(int v=0;v<n;v++)h[v]+=dist[v];

    int d=f;
    for(int v=t;v != s;v = prevv[v]){
      //cout <<"test " << v << endl;
      //      cout <<"test " << v <<" <- " << prevv[v]<<endl;
      d=min(d,G[prevv[v]][preve[v]].cap);
    }
    f-=d;
    //cout <<"flow " << f << " " << d*dist[t] << endl;
    res+=d*h[t];
    for(int v=t;v != s;v = prevv[v]){
      Edge &e=G[prevv[v]][preve[v]];
      e.cap-=d;
      G[v][e.rev].cap+=d;
    }
  }
  return res;
}


double calc(double x,double y,double z){
  return sqrt(x*x+y*y+z*z);
}

#define IN(i)  (i*2)
#define OUT(i) (i*2+1)

void solve(int n,int k,double *x,double *y,double *z){
  bool cansolve=true;
  rep(i,n){
    int cnt=0;
    rep(j,n){
      if (z[i]==z[j])cnt++;

    }
    if (cnt > k)cansolve=false;
  }
  if (!cansolve){
    printf("-1\n");
    return;
  }    

  if (n <= k){
    printf("0\n");
    return;
  }

  double ans = 1e100;
  REP(t,1,k+1){
    rep(i,2*n+2)G[i].clear();
    rep(i,n){
      rep(j,n){
	if (z[i] > z[j])
	  add_edge(IN(i),OUT(j),1,calc(x[i]-x[j],y[i]-y[j],z[i]-z[j]));
      }
      add_edge(2*n,IN(i),1,0);
      add_edge(OUT(i),2*n+1,1,0);
    }

     rep(i,n*2+2){
       //cout <<i<<":" <<  G[i].size() << endl;
       rep(j,G[i].size()){
	 //cout << i <<" " << G[i][j].to <<" " << G[i][j].cap <<
	 //"/" << G[i][j].cost << endl;
       }
     }
    
    double tmp = min_cost_flow(2*n+2,2*n,2*n+1,n-t);
    //cout << t <<" " << tmp << endl;
    if (tmp == -1)continue;
    ans=min(ans,tmp);
  }  
  //cout <<"ans " << ans << endl;
  printf("%.16lf\n",ans);
}

main(){
  int n,k;
  double x[N],y[N],z[N];
  while(cin>>n>>k && n){
    int m=2*n+2;
    rep(i,2*n+2)G[i].clear();
    rep(i,n)cin>>x[i]>>y[i]>>z[i];
    solve(n,k,x,y,z);
  }
  return false;
}
