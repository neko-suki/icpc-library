//二分木 多分ネタライブラリ
//

#include<iostream>
#include<complex>
using namespace std;
template<class T>
struct node{
  T data;
  struct node *lson,*rson;
};

template<class T>
class Binary_tree{
public:
  node<T> *root;
  Binary_tree(){}
  Binary_tree(T ini){//初期化
    root = malloc(sizeof(node<T>));
    root.data=ini;
    root.lson=root.rson=NULL;//ある場所より小さい値をlsonに加える。
  }
  
  bool findvalue(T search){
    if ( find(search) == NULL)return false;
    else return true;
  }
  node<T>*  find(T search){
    node<T> *p;
    p=root;
    while(p!=NULL){
      if ( p.data == search)return p;//値が見つかった場合
      else if (p.data < search)p=p.lson;
      else p =p.rson;
    }
    return p;
  }
  bool insert(T ins){
    node<T> *p,*q;
    p=root;
    while(p!=NULL){
      q = p;
      if ( ins == p.data)return false;
      if ( ins < p.data)p=p.lson;//今みているノードより左にいれる場合。
      else p = p.rson; //今みているノードより右にいれる場合。
    }
    p = malloc(sizeof(node<T>));
    if ( p == NULL)return false;
    p.data = ins;
    p.lson=p.rson=NULL;
    if ( ins < q.data)q.lson=p;
    else q.rson =p;
  }
  bool deletion(T del){
    node<T> *p,*q,*f;
    p=root;
    while(del!=p.data && p!=NULL){
      f = p;
      if ( p.data >del)p=p.lson;
      else p=p.rson;
    }
    if ( p == NULL)return 0;
    if ( p.lson == NULL || p.rson ==NULL){
      if ( p.lson==NULL)q=p.rson;
      else q = p.lson;
      if (f.lson ==p)f.lson= q;
      else f.rson = q;
    }else {
      q=p.rson;f=q;
      while(q.lson!=NULL){//successor を探す(スペルは適当)
	f=q;q=q.lson;
      }
      p.data=q.data;
      if ( q == f)p.rson = q.rson;
      else f.lson= q.rson;
    }
    return true;
  }

};





main(){
  return 0;
}
