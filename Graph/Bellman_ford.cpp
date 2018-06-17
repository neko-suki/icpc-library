//ベルマンフォードのアルゴリズムを用いて最短経路問題を解く
//

// UVa558 
#include<vector>

#define MAX 1<<21
#define N 1001

typedef pair<int,int> P;


int cost[N];
int edge[N][N];
int pi[N];



void reset(){
  for(int i=0;i<N;i++){
    cost[i]=MAX;
    pi[i]=-1;
    for(int j=0;j<N;j++){
      edge[i][j]=0;
    }
  }
}


void relax(int u,int v){
  if (cost[v]>cost[u]+edge[u][v]){
    cost[v]=cost[u]+edge[u][v];
    pi[v]=pi[u];
  }
}



int bellman_ford(int n,vector<P> A){
  for(int numberofnode=0;numberofnode<n-1;numberofnode++){//nodeの数だけ
    vector<P>::iterator it=A.begin();
    while(it != A.end()){
      relax((*it).first,(*it).second);
      it++;
    }
  }
  
  vector<P>::iterator it=A.begin();
  int u,v;
  while(it != A.end()){
    u = (*it).first;
    v = (*it).second;
    if (cost[v] > cost[u]+edge[u][v])return false;
    it++;
  }
  
  return true;
}


