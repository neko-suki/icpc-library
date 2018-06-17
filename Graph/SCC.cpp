//archive 5053
//uva 247,10510
const int N = 3000;
vector<int> edge[N];
vector<int> redge[N];
int component[N];
vector<int> node;
bool vis[N];
int order;

void dfs(int now){
  if (vis[now])return;
  vis[now]=true;
  rep(i,(int)edge[now].size()){
    dfs(edge[now][i]);
  }
  node.pb(now);
}

void dfs(int now,int cmp){
  if (vis[now])return;
  vis[now]=true;
  component[now]=cmp;
  rep(i,(int)redge[now].size()){
    dfs(redge[now][i],cmp);
  }
}

void scc(int n){
  node.clear();
  rep(i,n)vis[i]=false;
  rep(i,n){
    if (!vis[i])dfs(i);
  }
  reverse(node.begin(),node.end());
  rep(i,n)vis[i]=false;
  int comp=0;
  rep(i,n){
    int now=node[i];
    if (!vis[now])dfs(now,comp),comp++;
  }
}

