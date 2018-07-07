const int N   = 1024;
const int INF = (1<<20);
class st{
 public:
  int now, cost;
  st(int tnow, int tcost): now(tnow), cost(tcost){}
  bool operator>(const  st & a)const{
    if (cost != a.cost)return cost > a.cost;
    return now > a.now;
  }
};
 
struct Edge{
  int next;
  int cost;
};
 
vector<Edge> edge[N];
int cost[N];
int dijkstra(int n, int s, int t){
  fill(cost, cost+N, INF);
  cost[s] = 0;
  priority_queue<st, vector<st>, greater<st> > pq;
  pq.push(st(s, 0));
  while(!pq.empty()){
    st now = pq.top();pq.pop();
    //cout << now.now <<" " << now.cost << endl;
    if (now.cost != cost[now.now])continue;
    for(int i = 0;i < SZ(edge[now.now]);i++){
      int next = edge[now.now][i].next;
      int nec  = now.cost + edge[now.now][i].cost;
      if (nec < cost[next]){
        cost[next] = nec;
        pq.push(st(next, nec));
      }
    }
  }
  return cost[t];
}
 
