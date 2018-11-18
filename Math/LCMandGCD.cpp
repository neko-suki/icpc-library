//LCM and GCD

//w > m が前提
/*
  int gcd(int w,int m){
  if ( m == 0)return w;
  else return gcd(m,w%m);
  }

 */
int gcd(int w,int m){
  while(1){
    if (w %  m==0)return m;
    int temp;
    temp = w%m;
    w = m;
    m = temp;
  }
}

long long lcm(long long w,long long m){
  return (w*m)/gcd(w,m) ;//w > m
}



