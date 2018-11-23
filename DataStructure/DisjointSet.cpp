//Disjoint Set

//Accepted 
//uva 793,273,10685
//
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
    for(int i =0;i < size;i++){
      make_set(i);
    }
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



main(){
  DisjointSet dis(10);//size
  for(int i=0;i<10;i++){
    dis.make_set(i);
  }
  dis.merge(0,1);
  dis.merge(0,2);
  dis.merge(1,2);
  dis.merge(1,3);
  dis.merge(4,5);
  dis.merge(4,6);
  dis.merge(7,8);
  
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if (i == j)continue;
      if ( dis.find_set(i) == dis.find_set(j))cout << i << "==" << j << endl;
      //else cout << i <<"!=" << j <<endl;
    }
    
  }
  
  
}
