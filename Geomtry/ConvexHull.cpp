//convex hull
//

//update 2009/6/21
// uva accept 218.11626,681
#include<iostream>
#include<complex>
#include<algorithm>
#include<cassert>
using namespace std;
typedef complex<double> P;
//typedef complex<int> P;
#define EPS 1e-12
#define SIZE N
double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}
//一直線のデータを省く時は<0,省きたくない時は<=0にするといい。
int ccw(P a,P b){
    if ( cross(a,b) <0)return 1;
    else return -1;
}
bool cmp(const P&a,const P&b){
  if ( a.real() != b.real())return a.real()<b.real();
  else return a.imag() < b.imag();
}

//最後の点は入力の最初のテント同じになっているので注意。
void ConvexHull(int n,P *inp,P *out,int &p){
  sort(inp,inp+n,cmp);
  bool used[n];
  int num[n];
  fill(used,used+n,false);
  p=0;
  out[p++]=inp[0];out[p++]=inp[1];
  used[1]=true;
  num[0]=0;num[1]=1;
  for(int i=2;i<n;i++){
    while(p>=2){
      if ( ccw(out[p-1]-out[p-2],inp[i]-out[p-2]) ==1)break;
      else {
	used[num[p-1]]=false;
	p--;
      }
    }
    num[p]=i;
    used[i]=true;
    out[p++]=inp[i];
  }
  for(int i=n-2,t=p+1;i>=0;i--){
    if ( used[i] == true)continue;
    while(p>=t){//すでに凸包になった点を消さないようにする。
      if ( ccw(out[p-1]-out[p-2],inp[i]-out[p-2]) ==1)break;
      else p--;
    }
    out[p++]=inp[i];
  }
  
  return;
}

/*
  judge data for uva681
  uva 681
main(){
  int te,dummy;
  cin>> te;
  cout << te<<endl;
  while(te--){
    int n,p=0;
    cin>>n;
    P inp[n],out[n];
    for(int i=0;i<n;i++){
      cin >> inp[i].real() >> inp[i].imag();
    }
    n--;
    assert(n>=3);
    if ( te)cin >> dummy;
    ConvexHull(n,inp,out,p);
    p--;
    int min_index=0;
    for(int i=1;i<p;i++){      
      if (out[i].imag()<out[min_index].imag()){
	min_index=i;
      }else if ( out[i].imag()==out[min_index].imag() &&
		 out[i].real()<out[min_index].real()){
	min_index=i;
      }
    }
    cout << p+1 << endl;
    for(int i=min_index;i>=0;i--){
      printf("%.0lf %.0lf\n",out[i].real(), out[i].imag());
    }
    for(int i=p-1;i>=min_index;i--){
      printf("%.0lf %.0lf\n",out[i].real(), out[i].imag());
    }
    if ( te)cout << -1<<endl;
  }
  return false;
}

*/
/*
  judge data for uva 218

main(){
  int n;
  int te=0;
  while(cin>>n&&n){
    if ( te)putchar('\n');

    P inp[n],out[n];
    int p=0;
    for(int i=0;i<n;i++)cin>>inp[i].real()>>inp[i].imag();
    ConvexHull(n,inp,out,p);
    printf("Region #%d:\n",++te);
    double length=0;
    for(int i=0;i<p;i++){
      if ( i != 0)putchar('-');
      printf("(%.1lf,%.1lf)",out[i].real(),out[i].imag());
      if ( i == p-1)break;
      length+=abs(out[i]-out[i+1]);      
    }
    printf("\nPerimeter length = %.2lf\n",length);
  }
}

critical input
5
0 0
1 1
2 2
3 3
3 0
*/


/*uva 11626
main(){
  int te;
  cin>>te;
  while(te--){
    int n,p=0,m=0;
    cin>>n;
    P inp[n],out[n];
    for(int i=0;i<n;i++){
      double x,y;char c;
      cin>>x>>y>>c;
      if ( c == 'Y'){
	inp[m].real()=x;
	inp[m++].imag()=y;
      }
    }
    ConvexHull(m,inp,out,p);
    cout << p-1<<endl;
    printf("%.0lf %.0lf\n",out[0].real(),out[0].imag());  
    for(int i=p-2;i>0;i--){
      printf("%.0lf %.0lf\n",out[i].real(),out[i].imag());
    }
  }
}
*/
