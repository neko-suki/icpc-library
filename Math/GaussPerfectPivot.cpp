//ガウスの久殿恕 
//窗链联买拉
//

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
bool select_pivot(int n,int k,double mat[N][N],int num[N]){
  int s=k,t=k;//selected pivot
  double val=fabs(mat[k][k]);
  REP(i,k+1,n){
    REP(j,k+1,n){
      if (fabs(mat[i][j]) >val){
	val=fabs(mat[i][j]);
	s=i;
	t=j;
      }
    }
  }

  if ( val<eps)return false;//cannot solve this linear equations.
  
  rep(i,n)swap(mat[i][k],mat[i][t]);

  swap(num[k],num[t]);
  
  REP(i,k,n+1){
    swap(mat[k][i],mat[s][i]);
  }
  
  return true;//no problem for this pivot;
}

//n matrix size  x0,x1,...xn-1 =constant
//row n,column n+1
bool gauss(int n,double mat[N][N],double ret[N]){
  int num[N];
  //step 0
  rep(i,N)num[i]=i;

  //step1
  rep(k,n){
    if ( select_pivot(n,k,mat,num)==false)return false;
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

  //step3
  rep(i,n){
    ret[num[i]]=mat[i][n];
  }
  return true;
}

#define INF ( 1 << 25)

main(){
  int n,s,d;
  int adj[N][N];
  int cost[N][N];
  bool sign[N];
  double mat[N][N];
  double ans[N];
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
      }else {
	rep(j,n)
	  if (adj[i][j] != 0 )mat[i][n]+=adj[i][j],mat[i][j]=-1,cnt++;
      }
      mat[i][i]=cnt;
    }
       
    if (false == gauss(n,mat,ans)){puts("No Solution");return true;continue;}

    printf("%.14lf\n",ans[s]);
  }

  return false;
}


/*main for verify
main(){
  srand(time(NULL));
  int n =10;
  double ans[n];
  double ans2[n];
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

  if (  gauss(n, mat,ans2) == false){puts("Cannot solve");return false;}
  
  int cnt=0;
  
  rep(i,n){
    cout <<i << " " << ans[i] << " " << mat[i][n]<<" " 
	 << fabs(ans[i]-mat[i][n]) << endl;
    if ( fabs(ans[i]-mat[i][n])>eps)cnt++;
  }
  

   
  rep(i,n){
    cout << i <<" " << ans[i] << " " << ans2[i] << " " 
	 << fabs(ans[i]-ans2[i])<<endl;
  }
  
  cout << "number of WA is " << cnt << endl;
}
*/
