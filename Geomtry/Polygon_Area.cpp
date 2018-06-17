//多角形の面積

#include<iostream>
#include<complex>
#include<cstdio>
using namespace std;

typedef complex<int> P;

double Polygon_Area(const P *a,int n){
  int sum = 0;
  for(int i=0;i<n;i++){
    sum += (a[i%n].real()-a[(i+1)%n].real())*(a[i%n].imag()+a[(i+1)%n].imag());
  }
  return (double)(sum/2.0);
}

main(){
  int n,dataset=1;;
  while(cin >> n && n){
    P a[n];
    for(int i=0;i<n;i++){
      cin >> a[i].real() >> a[i].imag();
    }
    double ans=Polygon_Area(a,n);
    if ( ans > 0)ans*=-1;
    printf("%d %.1lf\n",dataset++,ans);
  }
}
