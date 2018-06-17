//ガウスの久殿恕
//ピボットは婶尸联买扩
//n*n あるいはr*cに滦炳

//accepted by rose 2171
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

#define N 101
const double eps = 1e-8;
//n matrix size  a00+x0+...=c0
//k current step
//mat Matrix
bool select_pivot(int n,int k,double mat[N][N]){
  int s=k;//selected pivot
  double val=fabs(mat[k][k]);
  REP(i,k+1,n)if (fabs(mat[i][k]) >val)val=fabs(mat[i][k]),s=i;
  
  if ( val<eps)return false;//cannot solve this linear equations.
  REP(i,k,n+1)swap(mat[k][i],mat[s][i]);
  return true;//no problem for this pivot;
}

//n matrix size  x0,x1,...xn-1 =constant
//row n,column n+1
bool gauss(int n,double mat[N][N]){
  //step1
  rep(k,n){
    if ( select_pivot(n,k,mat)==false)return false;
    REP(i,k+1,n+1)mat[k][i]/=mat[k][k];//devided by m[k][k];
    mat[k][k]=1;//for looking the equation
    REP(i,k+1,n){//洛掐
      REP(j,k+1,n+1)mat[i][j]+=-mat[i][k]*mat[k][j];
      mat[i][k]=0;//For looking the equation
    }
  }
  
  //step2 
  for(int i=n-1;i>=0;i--){//solve ith row
    REP(j,i+1,n){
      mat[i][n]-=mat[i][j]*mat[j][n];
    }
  }

  return true;
}
/*
bool select_pivot(int r,int c,int k,Q mat[N][N]){
  int s=k;
  ll val=mat[k][k].myabs();
  REP(i,k+1,r){
    if (mat[i][k].myabs()>val)val=mat[i][k].myabs(),s=i;
  }
  if (val ==0)return false;

  REP(i,k,c+1)swap(mat[k][i],mat[s][i]);
  return true;
}

bool gauss(int r,int c,Q mat[N][N]){
  rep(k,c){
    if (!select_pivot(r,c,k,mat)){
      return false;
    }
    REP(i,k+1,c+1)mat[k][i]=mat[k][i]/mat[k][k];
    mat[k][k]=Q(1,1);
    REP(i,k+1,r){
      REP(j,k+1,c+1)mat[i][j]=mat[i][j]-(mat[i][k]*mat[k][j]);
      mat[i][k]=Q(0,1);
    }
  }
  for(int i=r-1;i>=0;i--){
    REP(j,i+1,c){
      mat[i][c]=mat[i][c]-(mat[i][j]*mat[j][c]);
    }
  }
  return true;
}
*/

#define INF ( 1 << 25)

main(){
  int n,s,d;
  int adj[N][N];
  int cost[N][N];
  bool sign[N];
  double mat[N][N];
  while(cin>>n>>s>>d && n){
    s--;d--;
    rep(i,n)cin>>sign[i];
    rep(i,n){
      rep(j,n){
	cin>>adj[i][j];
	cost[i][j]=adj[i][j]==0?INF:adj[i][j];
	mat[i][j]=0;
      }
      mat[i][n]=0;
      cost[i][i]=0;
    }
    
    rep(k,n)rep(i,n)rep(j,n)cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);

    rep(i,n){
      int cnt=0;
      if ( i == d){mat[i][i]=1;mat[i][n]=0;continue;}
      if (sign[i]==true){
	
	rep(j,n)
	  if ( adj[i][j] !=0 && cost[i][d]==adj[i][j]+cost[j][d])
	    mat[i][n]+=adj[i][j],mat[i][j]=-1,cnt++;
	

	/*
	int mincost=INF;
	rep(j,n)if (adj[i][j]!=0 )mincost=min(mincost,cost[j][d]);
	rep(j,n)
	  if ( adj[i][j] !=0 && mincost==cost[j][d])
	    mat[i][n]+=adj[i][j],mat[i][j]=-1,cnt++;
	*/

	//	rep(j,n)
	//  if ( adj[i][j] !=0 && cost[s][d]==cost[s][j]+cost[j][d])
	//    mat[i][n]+=adj[i][j],mat[i][j]=-1,cnt++;
	

      }else {
	rep(j,n)
	  if (adj[i][j] != 0 )mat[i][n]+=adj[i][j],mat[i][j]=-1,cnt++;
      }
      mat[i][i]=cnt;
    }
        
    if (false == gauss(n,mat)){puts("No Solution");return true;continue;}
        
    printf("%.14lf\n",mat[s][n]);

  }

  return false;
}


/*main for verify
main(){
  srand(time(NULL));
  int n =100;
  double ans[n];
  double mat[N][N];
  rep(i,n)ans[i]=(double)(RAND_MAX-rand())/(double)RAND_MAX;
  
  rep(i,n){
    double sum =0;
    rep(j,n){
      double tmp =(double)(RAND_MAX- rand())/(double)RAND_MAX;
      mat[i][j]=tmp;
      sum+=tmp*ans[j];
    }
    mat[i][n]=sum;
  }

  if (  gauss(n, mat) == false){puts("Cannot solve");return false;}
  
  int cnt=0;
  rep(i,n){
    cout <<i << " " << ans[i] << " " << mat[i][n]<<" " 
	 << fabs(ans[i]-mat[i][n]) << endl;
    if ( fabs(ans[i]-mat[i][n])>eps)cnt++;
  }
  cout << "number of WA is " << cnt << endl;
}
*/
