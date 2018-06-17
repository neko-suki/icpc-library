//kruskal

//accepted by rose1280
//accepted by uva10147,uva10397,uva10034
#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
public:
  vector<int> rank,p;
  
  DisjointSet(){}
  DisjointSet(int size){
    rank.resize(size,0);
    p.resize(size,0);
  }
  void make_set(int x){
    p[x]=x;
    rank[x]=0;
  }
  void merge(int x,int y){
    link(find_set(x),find_set(y));
  }
  void link(int x,int y){
    if (rank[x]>rank[y]){
      p[y]=x;
    }else {
      p[x]=y;
      if ( rank[x] ==rank[y])rank[y]+=1;
    }
  }
  int find_set(int x){
    if (x != p[x])p[x]=find_set(p[x]);
    return p[x];
  }
};

class Edge{
public:
  int from,to,cost;
  bool operator<(const Edge & a)const{
    if ( cost != a.cost)return cost<a.cost;
    else if ( from != a.from)return from < a.from;
    return to < a.to;
  }
};

void kruskal(vector<Edge> edge,int n){
  int total=0;
  DisjointSet dis(n);
  for(int i=0;i<n;i++){//０からn-1のとき
    dis.make_set(i);
  }
  sort(edge.begin(),edge.end());
  for(int i=0;i<edge.size();i++){
    int from=edge[i].from,to=edge[i].to;
    int cost = edge[i].cost;
    if ( dis.find_set(from)!=dis.find_set(to)){
      dis.merge(from,to);
      total+=cost;
    }
  }
  //check MST
  int check = dis.find_set(0);
  for(int i=1;i<n;i++){
    if ( dis.find_set(i)!= check)return ;//error
  }
  //return cost; // if OK
}

main(){
  //
  /*
    int p[n][0];
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      double dist = sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+
			 (p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
      Edge ins = {i,j,dist};
      data.push_back(ins);
    }
    }*/
}
