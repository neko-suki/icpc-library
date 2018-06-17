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
  int maxval;//������
  Fenwick(){}
  Fenwick(int n){
    data.resize(n,0);
    maxval=n;
  }
  T read(int idx,int tidx){//idx����tidx�ޤǤ��¤���롣
    T sum = 0;
    if ( idx == 0){//������tidx�ޤǤζ�֤��¤����Ȥ���
      while(tidx > 0){
	sum+=data[tidx];
	tidx-=(tidx & -tidx);
      }
      return sum;
    }
    else return read(0,tidx)-read(0,idx-1);//����¾�ΤȤ���
  }
  
  void update(int idx,T val){//�ǡ����Υ��åץǡ��Ȥ�Ԥ��Ȥ���
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
  Fenwick<long long> a(n+1);//fenwick tree �ι��ۡ�
  vector<int> b(n+1);//���ǡ����������ˬ�äƤ�����
  //�ǡ�����Ȥ롣
  for(int i=0;i<n;i++){//����ǥå����ϰ줫����Ѥ��뤳�ȡ�
    long long  temp;
    cin >> temp;
    b[i+1]=temp;
    a.update(i+1,temp);
  }
  
  if ( inp == "M"){
    //������from����to���¤��᤿���Ȥ���
    cout << a.read(from,to) << endl;
  }
  else {
    //��������ͤ򹹿��������Ȥ���
    //��������ͤȸ����ͤκ������Ѥ��롣
    a.update(from,to-b[from]);
    b[from]=to;
    
  }
}

