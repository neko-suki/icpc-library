//バブルソートの交換回数を計算する。
//

//accepted by  	10327  	Flip Sort
#include<iostream>
#include<cstdio>
using namespace std;

#define MAX 10001
long long count;


void Merge(int a[],int l,int mid,int r){
  int n1 = mid - l+1,n2 = r-mid;
  int L[n1+1],R[n2+1];
  for(int i=0;i<n1;i++){
    L[i]=a[l+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=a[mid+i+1];
  }
  L[n1]=R[n2]=INT_MAX;
  int pr =0,pl = 0;
  for(int i=l;i<r+1;i++){
    if ( L[pl] <= R[pr]){
      a[i]=L[pl++];
    }
    else if (L[pl]>R[pr]){
      ::count+=n1-pl;
      //cout << R[pr] << endl;
      a[i]=R[pr++];
    }
  }
  
}

void MergeSort(int a[],int l,int r){
  if (l < r){
    int q = (r+l)/2;
    MergeSort(a,l,q);
    MergeSort(a,q+1,r);
    Merge(a,l,q,r);
  }

}



main(){
  int te;
  scanf("%d",&te);
  int n,count=0;
  while(te-- && scanf("%d",&n) ){
    
    int a[n];
    for(int i=0;i<n;i++){
      int temp;
      scanf("%d",&temp);
      a[i]=temp;
    }
    
    ::count = 0;
    MergeSort(a,0,n-1);
    cout << "Optimal train swapping takes "<<::count<<" swaps."<<endl;

  }
  
}
