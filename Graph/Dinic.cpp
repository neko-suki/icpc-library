//dinic


//accepted by 820
//accepted by 10249
//accepted by rose 2096//main not here because use long long...
//accepte by rose 1163
//accepted by 10330
#include<iostream>
#include<queue>

using namespace std;
//for maximum flow
#define MAX 200
#define INF (1 << 21)//#define INF (1LL << 60)
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
int cap[MAX][MAX];
bool visited[MAX];
int parent[MAX];
int flow[MAX][MAX];
int layer[MAX];

void make_layer(int n,int s,int t){
  queue<int> Q;
  Q.push(s);
  layer[s]=0;
  while(!Q.empty()){
    int now = Q.front();Q.pop();
    rep(i,n){
      if ( cap[now][i]-flow[now][i]>0 &&layer[i]==-1){
	layer[i]=layer[now]+1;
	Q.push(i);
      }
    }
  }
}

int augment(int now,int t,int n,int f){
  if ( now == t||f==0)return f;
  if ( visited[now])return 0;
  visited[now]=true;
  rep(i,n){
    if ( layer[now]<layer[i] ){
      int tmp=  augment(i,t,n,min(f,cap[now][i]-flow[now][i]));
      if ( tmp > 0){
	flow[now][i]+=tmp;
	flow[i][now]=-flow[now][i];
	visited[now]=false;
	return tmp;
      }
    }
  }
  return 0;
}

int dinic(int n,int s,int t){
  int ansflow=0;
  bool flag=true;
  rep(i,n)rep(j,n)flow[i][j]=0;
  while(flag){
    fill(layer,layer+n,-1);
    fill(visited,visited+n,false);
    flag = false;
    //make layer
    make_layer(n,s,t);
    if (layer[t]==-1)break;//if no such path to go to sink

    //find blocking flow
    for(int f=1;f;flag=true){
      f = augment(s,t,n,INF);
      if ( f == 0)break;
      ansflow+=f;
    }
  }
  return ansflow;
}
//end maximum flow


/*
//data for 10249
#define N 200
#define SOURCE 0
#define SINK   1
void solve(int n,int m){
  fill(&cap[0][0],&cap[N-1][N],0);
  int total=0;
  for(int i=0;i<n;i++){
    int t;
    scanf("%d",&t);
    total+=t;
    cap[SOURCE][i+2]=t;
  }
  for(int i=0;i<m;i++){
    int t;
    scanf("%d",&t);
    cap[2+n+i][SINK]=t;
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cap[2+i][2+n+j]=1;
  
  int ans = dinic(n+m+2,SOURCE,SINK);
  if (ans  != total){puts("0");return;}
  else puts("1");
  for(int i=0;i<n;i++){
    int cnt=0;
    for(int j=0;j<m;j++){
      if (flow[2+i][2+n+j] != 0){
	if ( cnt)putchar(' ');
	printf("%d",j+1),cnt++;	  
      }
    }
    putchar('\n');
  }
  
}

main(){
  int n,m;
  while(scanf("%d%d",&n,&m) && n)solve(n,m);
}
*/


/*
uva 820

main(){
  int n,te=0;
  while(cin >> n && n){
    int t,s,num;
    cin >> s >> t >> num;
    n++;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
	cap[i][j] = 0;
      }
    }
    for(int i=0;i<num;i++){
      int f,to,c;
      cin >> f >> to >> c;
      if( cap[f][to] != 0)cap[f][to]=cap[to][f]+=c;
      else cap[f][to]=cap[to][f]=c;
    }
    cout << "Network "  << ++te << endl;
    cout << "The bandwidth is " << dinic(n+1,s,t)<< "." << endl;
    puts("");
  }
  return 0;
}
*/
