//巡回セールスマン問題

//accepted by UVa 10944,10496,216
#include<iostream>
using namespace std;
#define SIZE 11
#define INF (1 << 21)
int graph[21][21];
int tsp(int n){
  int dp[(1 << n)][n];
  for(int i=0;i<(1 << n);i++)for(int j=0;j<n;j++)dp[i][j]=INF;
  for(int i=1;i<n;i++){
    dp[1<<i][i]=graph[0][i];
  }
  for(int i=0;i<( 1<< n);i++){
    for(int j=0;j<n;j++){
      if ( dp[i][j] == INF)continue;
      if ( i & (1 << j) == 0)continue;
      for(int k=0;k<n;k++){
	int next = (1 << k);
	if ( (i&next) != 0)continue;
	dp[i|next][k]=min(dp[i|next][k],dp[i][j]+graph[j][k]);
      }
    }
  }

  return dp[(1 << n)-1][0];
}
