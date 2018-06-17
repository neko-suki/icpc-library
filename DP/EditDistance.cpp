//Edit Distance
//
//accpeted by uva526,uva164
//
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;

//change string in row to string in column
//行に配置したストリングをcolumnに配置したストリングに変更する。
//example
//    '\0' a b c
//'\0' 0   1 2 3
// a   1   0 1 2
// b   2   1 0 1
//
// deletion   d[i-1][j]+1 //
// insertion  d[i][j-1]+1
// substition d[i][j]+cost: if (r[i]==c[j])cost=0;else cost=1;
#define MATCH      0
#define SUBSTITUTE 1
#define DELETE     3
#define INSERT     2
#define K  4//操作の種類
#define NDEBUG
int ptr;
void make_path(vector<int>  path[],int rp,int cp,string r,string c){
  if ( rp <0 || cp < 0)return;
  if ( path[rp][cp] == MATCH){
    make_path(path,rp-1,cp-1,r,c);
  }else if (path[rp][cp]==SUBSTITUTE){
    make_path(path,rp-1,cp-1,r,c);
    //cout << r[rp] << " is replaced to " << c[cp]<<endl;
    printf("C%c%02d",c[cp],cp);
  }else if ( path[rp][cp]==DELETE){
    make_path(path,rp-1,cp,r,c);
    //cout << "DELETE " << r[rp] << endl;
    printf("D%c%02d",r[rp],rp+ptr);
    ptr--;
  }else if (path[rp][cp] == INSERT){
    make_path(path,rp,cp-1,r,c);
    //cout << "INSERT " << c[cp] << endl;
    printf("I%c%02d",c[cp],cp);
    ptr++;
  }
  return ;
}


void edit_distance(string r,string c){
  ptr=0;
  r = ' '+r;
  c = ' '+c;
  //int d[r.length()][c.length()];
  vector<int> d[r.length()];
  vector<int> path[r.length()];
  //int path[r.length()][c.length()];
  for(int j=0;j<r.length();j++){
    d[j].resize(c.length()+1,0);
    d[j][0]=j;
    path[j].resize(c.length()+1,0);
    path[j][0]=DELETE;
  }
  for(int i=0;i<c.length();i++){
    d[0][i]=i;
    path[0][i] = INSERT;
  }
  path[0][0]=-1;
  
  for(int i=1;i<r.length();i++){
    for(int j=1;j<c.length();j++){
      int cost= r[i] == c[j]?0:1;
      int opt[K];//最適コスト
      int maypath=0;
      if ( cost == 0)maypath=MATCH;
      else maypath = SUBSTITUTE;
      opt[0]=d[i-1][j-1]+cost;
      opt[DELETE]=d[i-1][j]+1;
      opt[INSERT]=d[i][j-1]+1;
      d[i][j]=opt[MATCH];
      path[i][j]=maypath;
      for(int k=INSERT;k<=DELETE;k++){
	if ( opt[k] <= d[i][j]){
	  d[i][j]=opt[k];
	  path[i][j]=k;
	}
      }
    }
  }
  make_path(path,r.length()-1,c.length()-1,r,c);
  assert(d[r.length()-1][c.length()-1]  <=20);
  cout << endl << d[r.length()-1][c.length()-1] << endl;
  return;
  //return d[r.length()-1][c.length()-1];
}


main(){
  
  while(1){
    string temp;
    getline(cin,temp);
    int p=0;
    if ( temp[p]=='#')break;
    for(p=0;p<temp.length();p++){
      if ( temp[p]==' ')break;
    }
    if ( p == temp.length())p=0;
    string be,af;
    be = temp.substr(0,p);
    af = temp.substr(p+1);
    //cout << be << af << endl;
    //cin >> be >> af;
    int findspace=0;
    if ( be[0]=='#')break;
    /*
    for(int i=0;i<temp.length();i++,findspace = i){
      if ( temp[i]==' ')break;
    }
    be = temp.substr(0,findspace);
    af = temp.substr(findspace+1);
    */edit_distance(be,af);
    puts("E");
  }
}
