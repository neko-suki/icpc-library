//無向グラフの関節点を求める
/*

1  The root of the graph is articulation if it has at least two children.
2  v is an articulation point if and only if v has a child s
   that there is no back edge from s or any descendant of s to a "proper ancestor" of v.
ancestor,descendantは自分自身を含むが,proper ancestor,proper descendantは自分自身を含まない。

low[v]=min{d[v],d[w]:(u,w)is a back edge for some descendant u of v
最終的にlow[v]とd[w]を比較してlow[v]の方が低ければ関節点にはならない。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define N 1000

vector<int> edge[N];
bool visited[N];
bool isroot[N];
int d[N];//discoverd time  
int low[N];

void dfs(int now,int prev,int &time){
  visited[now]=true;
  low[now]=d[now]=time++;
  rep(i,edge[now].size()){
    int next =edge[now][i];
    if ( visited[next] == false){
      dfs(next,now,time);
      low[now]=min(low[now],low[next]);
    }else if ( next != prev)low[now]=min(low[now],d[next]);//prev should be proper ancestor
  }
}

vector<int> Articulation_Point(int n){
  vector<int> ret;
  rep(i,n)visited[i]=false,isroot[i]=false;
  int time=0;
  rep(i,n){
    if (visited[i] == false){
      dfs(i,-1,time);
      isroot[i]=true;
    }
  }

  rep(i,n){
    if ( isroot[i]){
      if ( edge[i].size() >=2)ret.push_back(i);
    }else {
      bool flag=true;
      rep(j,edge[i].size())if ( d[i] < d[edge[i][j]] && d[i] <low[edge[i][j]])flag=false;
      if ( flag)ret.push_back(i);
    }
  }

  rep(i,ret.size())cout <<"node " << 1+ ret[i] << endl;
  return ret;
}


//main for uva 315
#include<sstream>
main(){
  int n;
  while(cin >> n &&n){
    rep(i,n)edge[i].clear();
    cin.ignore();
    string temp;
    for(int i=0;getline(cin,temp);i++){
      if ( temp == "0")break;
      stringstream sin(temp);
      int s,t;
      sin >> s;
      while(sin >> t){
	edge[s-1].push_back(t-1);
	edge[t-1].push_back(s-1);
      }
    }
    vector<int> AP=Articulation_Point(n);
    cout << AP.size() << endl;
  }
  return false;
}




//lib from here
//accepted by UVa 315
/*
#include<iostream>
#include<vector>
#include<set>
#include<sstream>
using namespace std;
#define SIZE 10000
vector<int> Edge[SIZE];
int low[SIZE];
int num[SIZE];
int parent[SIZE];
bool visited[SIZE];
int step;
void dfs(int now,int prev){
  num[now]=step++;
  visited[now]=true;
  low[now]=num[now];
  for(int i=0;i<Edge[now].size();i++){
    int next = Edge[now][i];
    if  ( visited[next]== false){
      parent[next]=now;
      dfs(next,now);
      low[now]=min(low[now],low[next]);
    }else if ( next != prev){// back edge 
      low[now]=min(low[now],num[next]);
    }
  }
}

int Articulation_point(int n){
  step = 0;
  int root = 0,ans = 0,check = 0;
  num[root]=step++;
  visited[root]=true;
  parent[root]=-1;
  low[root] = 0;
  for(int i=0;i<Edge[root].size();i++){
    int next = Edge[root][i];
    if ( visited[next] == false){
      check++;
      parent[next]=root;
      dfs(next,root);
    }
  }
  set<int> S;
  for(int i=1;i<n;i++){
    int p=parent[i];
    if (p == 0)continue;
    if ( num[p] <= low[i]){
      S.insert(p);
    } 
  }
  
  if ( check >=2)S.insert(0);
  return S.size();
}


void reset(int n){
  for(int i=0;i<n;i++){
    Edge[i].clear();
    visited[i]=false;
    parent[i]=-1;
  }
}
//lib end here


main(){
  int n;
  while(cin >> n &&n){
    reset(n);cin.ignore();
    string temp;
    for(int i=0;getline(cin,temp);i++){
      if ( temp == "0")break;
      stringstream sin(temp);
      int s,t;
      sin >> s;
      while(sin >> t){
	Edge[s-1].push_back(t-1);
	Edge[t-1].push_back(s-1);
      }
    }
    cout <<Articulation_point(n) << endl;
  }
  return false;
}
*/
