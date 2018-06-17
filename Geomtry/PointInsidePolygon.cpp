//驴逞妨が爬を柒蜀するかどうかを冉年する。

bool is_in(P* in,P a){
  int cnt =0;
  int n = 3;
  rep(i,n){
    P cur = in[i]-a,next=in[(i+1)%n]-a;
    if (cur.imag() > next.imag())swap(cur,next);
    if (cur.imag()<0 && 0<=next.imag() &&
	cross(next,cur)>=0)cnt++;
    if (isp(in[i],in[(i+1)%n],a))return true;
  }

  if (cnt %2 == 1)return true;
  else return false;
}

