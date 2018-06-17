//２次元平面上での最近点対を求める
//

//accepter by 10245
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
class Point{
public:
  double x,y;
  bool operator<(const Point & a)const{
    if ( x != a.x)return x < a.x;
    return y < a.y;
  }
  double dist(Point & a){
    return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));
  }
};
double min_val=10000;//need to insert Largest value
#define MAXPOINT 1e250
Point BigPoint ={MAXPOINT,MAXPOINT};

void Merge(Point *a,int l,int mid,int r,double midx){
  int n1 = mid-l+1,n2 = r-mid,pr=0,pl=0;
  Point L[n1+1],R[n2+1];
  for(int i=0;i<n1;i++)L[i]=a[l+i];
  for(int i=0;i<n2;i++)R[i]=a[mid+1+i];
  L[n1]=R[n2]=BigPoint;
  for(int i=l;i<r+1;i++){
    if ( L[pl].y < R[pr].y)a[i]=L[pl++];
    else a[i]=R[pr++];
  }
  Point p1=BigPoint,p2=BigPoint,p3=BigPoint,p4=BigPoint;
  for(int i=l;i<r+1;i++){
    if ( abs(midx-a[i].x)< min_val){
      min_val=min(min_val,a[i].dist(p1));
      min_val=min(min_val,a[i].dist(p2));
      min_val=min(min_val,a[i].dist(p3));
      min_val=min(min_val,a[i].dist(p4));
      p1=p2;p2=p3;p3=p4;p4=a[i];
    } 
  }
}


void MergeSort(Point *a,int l,int r){//include r that means <=r
  if ( l<r){
    int q = (r+l)/2;
    double midx = a[q].x;
    MergeSort(a,l,q);
    MergeSort(a,q+1,r);
    Merge(a,l,q,r,midx);
  }
}

/*
main(){
//uva 10245.main
int n;
  while(cin >>n && n){
    min_val = 10000;
    Point a[n];
    for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
    sort(a,a+n);
    MergeSort(a,0,n-1);
    if ( min_val >=10000)puts("INFINITY");
    else printf("%.4lf\n",min_val);
  }
}
*/
