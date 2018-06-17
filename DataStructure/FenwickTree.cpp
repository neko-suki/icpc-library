//Fenwick tree

//accepted by arc2191
//accepted by uva10324(only read);
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class Fenwick{
public:
  vector<T> data;
  int maxval;//最大値
  Fenwick(){}
  Fenwick(int n){
    data.resize(n,0);
    maxval=n;
  }
  T read(int idx,int tidx){//idxからtidxまでの和を求める。
    T sum = 0;
    if ( idx == 0){//０からtidxまでの区間の和を求めるとき。
      while(tidx > 0){
	sum+=data[tidx];
	tidx-=(tidx & -tidx);
      }
      return sum;
    }
    else return read(0,tidx)-read(0,idx-1);//その他のとき。
  }
  
  void update(int idx,T val){//データのアップデートを行うとき。
    while(idx <=maxval){
      data[idx]+=val;
      idx+=(idx & -idx);
    }
  }
};

main(){
  int test=1;
  int n;
  cin >> n;
  Fenwick<long long> a(n+1);//fenwick tree の構築。
  vector<int> b(n+1);//元データの配列を訪っておく。
  //データをとる。
  for(int i=0;i<n;i++){//インデックスは一から使用すること。
    long long  temp;
    cin >> temp;
    b[i+1]=temp;
    a.update(i+1,temp);
  }
  
  if ( inp == "M"){
    //ある区間fromからtoの和を求めたいとき。
    cout << a.read(from,to) << endl;
  }
  else {
    //ある場所の値を更新したいとき。
    //更新後の値と元の値の差を利用する。
    a.update(from,to-b[from]);
    b[from]=to;
    
  }
}

