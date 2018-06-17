//trieĚÚ

//acceptedby895
#include<iostream>
#include<algorithm>
using namespace std;

class Trie{
public:
  int flag;
  Trie *next[256];
  Trie(){
    flag = 0;
    fill(next,next+256,(Trie*)0);
  }
  void insert(string a){
    Trie *p=(this);
    for(int i=0;i<a.size();i++){
      Trie *tmp=p->next[a[i]];
      if ( tmp == 0)tmp=new Trie;
      p=p->next[a[i]]=tmp;
    }
    p->flag++;
  }
  int find(char *a,int size){
    Trie *p=(this);
    for(int i=0;i<size;i++){
      Trie *tmp =p->next[a[i]];
      if ( tmp == 0)return false;
      p=p->next[a[i]];
    }
    return p->flag;
  }  
};

int cnt = 0;
void solve(char *ch,int *num,int p,Trie root,char *tar,int now){
  cnt+=root.find(tar,now);

  if ( now == p)return;
  for(int i=0;i<p;i++){
    if ( num[i] ==0)continue;
    tar[now]=ch[i];
    num[i]--;
    solve(ch,num,p,root,tar,now+1);
    num[i]++;
  }

}

main(){
  string a;
  Trie root;
  while(getline(cin,a) && a != "#"){
    root.insert(a);
  }
  
  while(getline(cin,a) && a !="#"){
    string tar;
    for(int i=0;i<a.size();i++)if ( a[i] !=' ')tar+=a[i];
    sort(tar.begin(),tar.end());
    char ch[10],target[10];
    int num[10]={0};
    int p=0;
    for(int i=0;i<tar.size();){
      char temp = tar[i];
      ch[p]=tar[i];
      while(i<tar.size() && tar[i]==temp){
	num[p]++;
	i++;
      }
      p++;
    }
    
    
    cnt =0;
    solve(ch,num,p,root,target,0);
    cout << cnt << endl;
  }

}
