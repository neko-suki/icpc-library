//Edmonds karp
//

//accepted by uva820
//accepted by rose2064
//edgeは妥らないっぽい
//O(|V||E|^2)
#include<iostream>
#include<queue>

using namespace std;
//for maximum flow
#define MAX 200
int capacity[MAX][MAX];
bool visited[MAX];
//bool edge[MAX][MAX];
int parent[MAX];
int flow[MAX][MAX];
int bfs(int n,int s,int t){
  int mincapacity[n];
  for(int i=0;i<n;i++){
    parent[i]=-1;
    visited[i] = false;
  }
  queue<int> Q;
  Q.push(s);
  visited[s] = true;
  mincapacity[s]=(1 << 21);
  while(!Q.empty()){
    int now = Q.front();
    Q.pop();
    for(int i=1;i<n;i++){
      //cout << now << " " << i << " " << edge[now][i] << endl;
      //if ( edge[now][i] == false)continue;
      if ( visited[i] == true)continue;
      if ( capacity[now][i]-flow[now][i]>0 ){
	parent[i]=now;
	visited[i]=true;
	mincapacity[i]= min(mincapacity[now],capacity[now][i]-flow[now][i]);
	if ( i == t)return mincapacity[i];
	Q.push(i);
      }
    }
  }
  return -1;
}
int EdmondsKarp(int n,int s,int t){
  int ansflow=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      flow[i][j]=0;
    }
  }
  while(1){
    int minflow = bfs(n,s,t);
    if (minflow == -1)break;
    else ansflow+=minflow;
    int v = t;
    while( v != s){
      int u= parent[v];
      flow[u][v]=flow[u][v]+minflow;
      flow[v][u]=-flow[u][v];
      v =u;
    }
  }
  return ansflow;
}
//end maximum flow
//capacityの介袋步撕れに庙罢
main(){
 
  int n,te=0;
  while(cin >> n && n){
    int t,s,num;
    cin >> s >> t >> num;
    n++;
    for(int i=1;i<n;i++){
      for(int j=1;j<n;j++){
	//edge[i][j] = false;
	capacity[i][j] = 0;
      }
    }
    for(int i=0;i<num;i++){
      int f,to,cap;
      cin >> f >> to >> cap;
      if( capacity[f][to] != 0)capacity[f][to]=capacity[to][f]+=cap;
      else capacity[f][to]=capacity[to][f]=cap;
      edge[f][to]=edge[to][f]=true;
    }
    cout << "Network "  << ++te << endl;
    cout << "The bandwidth is " << EdmondsKarp(n,s,t)<< "." << endl;
    puts("");
  }
  return 0;
}
