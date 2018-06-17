//0-1ナップザック啼玛を豺く
//
//

//accepted by uva624,uva10130
//
//
#include<iostream>
#include<vector>
using namespace std;
//int px[]={0,data[i-j]};
//path[i][j]=1 means product i is in the knapsak 
void makepath(vector<int> & data,vector<int> path[],int nowy,int nowx){
  if ( path[nowy][nowx]==-1)return;
  if ( path[nowy][nowx]==1){
    makepath(data,path,nowy-1,nowx-data[nowy]);
    cout << data[nowy] << " ";
  }else {
    makepath(data,path,nowy-1,nowx);
  }
}


void knap(int w,vector<int> weight,vector<int> cost){
  int size = weight.size();
  vector<int> dp[size];
  vector<int> path[size];
  for(int i=0;i<size;i++){
    dp[i].resize(w+1,0);
    path[i].resize(w+1,0);
  }
  for(int i=0;i<w;i++){
    dp[0][i]=0;
    path[0][i]=-1;
  }
  for(int j=0;j<size;j++){
    dp[j][0]=0;
    path[j][0]=-1;
  }
  for(int i=1;i<size;i++){
    for(int j=1;j<=w;j++){
      if ( weight[i]>j ){
	dp[i][j]=dp[i-1][j];
	path[i][j]=0;
      }else if ( dp[i-1][j] > dp[i-1][j-weight[i]]+cost[i]){
	dp[i][j]=dp[i-1][j];
	path[i][j]=0;
      }else{
	dp[i][j]=dp[i-1][j-weight[i]]+cost[i];
	path[i][j]=1;
      }
    }
  }
  //makepath(cost,path,size-1,w);
  cout << dp[size-1][w] << endl;

}

main(){
  
  int maxweight,num;
  while(cin >> maxweight >> num){
    vector<int> inpw;
    vector<int> inpc;
    inpw.push_back(0);
    inpc.push_back(0);
    for(int i=0;i<num;i++){
      int tempw,tempc;
      cin >> tempw;
      inpw.push_back(tempw);
      inpc.push_back(tempc);
    }
    knap(maxweight,inpw,inpc);
  }
}
