//uva 481
//strictry increase sequence only
const int N = 1000000;
int dp[N];
int pos[N];
int path[N];

void lis(vector<int> &in){
  dp[0]=in[0];
  path[0]=-1;
  int n=1;
  REP(i,1,in.size()){
    int l=lower_bound(dp,dp+n,in[i])-dp;
    if (l == n){
      dp[n++]=in[i];
    }else dp[l]=in[i];
    pos[l]=i;
    if (l == 0)pos[i]=-1;
    else path[i]=pos[l-1];
  }

  printf("%d\n",n);
  printf("-\n");
  vector<int> ans;
  int now = pos[n-1];
  while(now != -1){
    ans.push_back(now);
    now=path[now];
  }
  reverse(ans.begin(),ans.end());
  rep(i,ans.size())printf("%d\n",in[ans[i]]);
}
