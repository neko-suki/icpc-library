//2次元グリッド上で最大の正方形を探す

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 1000
char data[MAX][MAX];
int dp[MAX][MAX];


int sq_search(int row,int column){
  int maxi = 0;
  for(int i=1;i<row;i++){
    for(int j=1;j<column;j++){
      if (dp[i][j] == 0)continue;
      dp[i][j] += min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
      maxi = max(maxi,dp[i][j]);
    }
  }
  return maxi;

}



main(){
  int n;
  while(cin >> n && n){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cin >> data[i][j];
	if (data[i][j] == '*')dp[i][j]=0;
	else dp[i][j]=1;
      }
    }
    
    cout <<sq_search(n,n) << endl;
  }



}
