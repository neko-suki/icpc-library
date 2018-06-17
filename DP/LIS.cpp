//LIS

#include<iostream>
#include<algorithm>
using namespace std;

#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

//SOLVE LIS
#define N 10000
#define L N+1
#define INF (1<<30)

int smis[L];//長さiのISで,i番目の値が最小のもの。
int len[N+1];//その数字が最後になるISの長さを求める
int path[N];//実際のパス

int binary_search(int *in,int val,int i){
  int l=0,r=i+1,mid,ret=0;
  while(l<r){
    mid=(r+l)/2;

    if ( in[mid] < val)l=mid+1,ret=mid;//strictly increasing
    //if ( in[mid] <= val)l=mid+1,ret=mid;//not strictly increasing
    else r=mid-1;
  }
  return ret;
}

int lis_nlogn(int n,int *in){
  int l=0;
  rep(i,n+1)smis[i]=INF,path[i]=-1;
  int curmax=0;//現在最長のIS
  rep(i,n){
    int tmp=binary_search(smis,in[i],curmax);
    len[i]=tmp+1;
    curmax=max(tmp+1,curmax);
    smis[tmp+1]=min(smis[tmp+1],in[i]);
  }

  //find path
  //長さが順に後ろから順番にとっていく
  int tmp=curmax;
  for(int i=n-1;i>=0;i--)
    if ( len[i] == tmp)path[--tmp]=in[i];
  
  return curmax;
}

main(){
  int a[]={1, 2, 3, 4, 5, 4, 3, 2, 1, 5};
  int n=10;
  int ans = lis_nlogn(n,a);
  
  cout <<"LIS is " << ans << endl;
  rep(i,ans)cout << path[i] <<" ";
  cout << endl;
}
