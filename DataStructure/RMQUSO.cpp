//区間[i,j]の間の最大値(最小値)を lognで求める
//セグメントツリー
//n*2^nのメモリを使用。
//find_val(0,0,l,r,0,65535)

int dp[N];
int data[17][N];
int find_val(int bit,int node,int lq,int rq,
	     int left,int right){
  if (data[bit][node] != -1 &&
      lq==left && rq == right){
    return data[bit][node];
  }
  int mid = (left+right)/2;
  if (left==right){
    return data[bit][node]=dp[lq];
  }

  int ret=0;
  if (rq <= mid){
    ret=find_val(bit+1,node*2  ,lq,rq,left ,mid);
  }else if (mid+1 <= lq){
    ret=find_val(bit+1,node*2+1,lq,rq,mid+1,right);
  }else {
    ret=max(ret,find_val(bit+1,node*2  ,lq   ,mid,left ,mid));
    ret=max(ret,find_val(bit+1,node*2+1,mid+1,rq ,mid+1,right));
  }
  
  if (lq == left && rq == right)data[bit][node]=ret;
  return ret;
}


main(){
  rep(i,17)rep(j,50000)data[i][j]=-1;

  srand(time(NULL));
 
  rep(i,50000){
    val[i]=rand()%10000000;
  }
  REP(i,50000,N)val[i]=0;

  
  int te = 50000;
  while(te--){
    int l = rand()%50000,r=rand()%50000;
    if (l > r)swap(l,r);
    int ans = 0,index=0;
    REP(i,l,r+1){
      if (ans < val[i])index =i,ans=val[i];
    }
    //cout <<index << " " << val[index] <<" " <<  ans << " " << find_val(0,0,l,r,0,49999) << endl;
    //find_val(0,0,l,r,0,49999);
    assert(find_val(0,0,l,r,0,65535)==ans);
  }

  return false;
}

