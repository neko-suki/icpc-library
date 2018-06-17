//Matric chain multiplication

//accepted by uva348
#include<iostream>
using namespace std;
#define MAX 10
#define INF (1 << 30)
class Matrix{
public:
  int row,column;
};
int data[MAX];
int path[MAX][MAX];
int cost[MAX][MAX];
int num;

void Print_optimal_parens(int i,int j,int n){
  if ( i == j)cout << "A"<<1+num++;
  else {
    putchar('(');
    Print_optimal_parens(i,path[i][j],n);
    if ( num != n)cout << " x " ;
    Print_optimal_parens(path[i][j]+1,j,n);
    putchar(')');
  }
}

void Matrix_chain_multiplication(int n,Matrix *inp){
  for(int i=0;i<n;i++){
    cost[i][i]=0;
  }
  for(int l=2;l<n+1;l++){
    for(int i=0;i<n-l+1;i++){
      int j=i+l-1;// matrix i to j separated by k
      cost[i][j] = INF;
      for(int k=i;k<j;k++){
	int temp = cost[i][k]+cost[k+1][j] + inp[i].row*inp[k+1].row*inp[j].column;
	cout << i << " " << j << " " << temp << endl;
	if ( temp < cost[i][j] ){
	  cost[i][j] = temp;
	  path[i][j] = k;
	}
      }
    }
  }
  cout << cost[0][n-1]   << endl;
}


main(){
  int n;
  int te=1;
  while(cin >> n && n){
    Matrix inp[n];
    for(int i=0;i<n;i++){
      cin >> inp[i].row >> inp[i].column;
    }
    cout << "Case "<<te++<<": ";
    Matrix_chain_multiplication(n,inp);
    num = 0;
    Print_optimal_parens(0,n-1,n);
    cout << endl;
  }
}
