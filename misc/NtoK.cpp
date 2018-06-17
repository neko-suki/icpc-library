//N 真数の文字列をK真数の文字列に変換する
//

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

char table[128];
char chartoint[128];

bool check_illegal(string data,int n){
  for(int i=0;i<data.length();i++){
    if ( isdigit(data[i]) || isalpha(data[i]));
    else return 1;
    if (chartoint[data[i]] >= n)return 1;
  }
  return 0;
}

string ntok(string data,int n,int k){
  if (check_illegal(data,n)) return "-1";
  long long total=0;
  long long multi = 1;
  for(int i=data.length()-1,j=0;i>=0;j++,i--){
    //total+=(int)(chartoint[data[i]]*pow(n,(double)j));
    total += (long long)(chartoint[data[i]]*multi);
    multi*=n;
  }

  string ret;
  while(1){
    ret+= table[total%k];
    if (total/k ==0){
      break;
    }
    total/=k;
  }
  reverse(ret.begin(),ret.end());
  return ret;
}


main(){
  string data;
  int from,to;
  for(int i=0,j='0';i<10;i++,j++)chartoint[j]=i;
  for(int i=10,j='A';j<='Z';i++,j++)chartoint[j]=i;
  for(int i=0;i<10;i++)table[i]=i+'0';
  for(int i='A',j=10;i<='Z';j++,i++)table[j]=i;




}
g
