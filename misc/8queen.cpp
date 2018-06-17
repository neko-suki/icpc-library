//8queen 問題を解く。
//

/*
  4types of judge,row,column,migi naname,hidari naname
  miginaname data[14],checkd with row+column;
  hidarinaname data[14]checkd with 7+row-column
  The path data is row.
*/
//accepted by UVa 167
//
//
//
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > Ans;
vector<int> path;
int row[8],column[8],rd[15],ld[15];

void eight_queen(int now){
  if ( now == 8){
    Ans.push_back(path);
    return; 
  }
  for(int i=0;i<8;i++){
    if ( row[i] == 0 && column[now] == 0 && rd[i+now]==0 && ld[7+i-now]==0){
      row[i]=1;column[now]=1;rd[i+now]=1;ld[7+i-now]=1;
      path[now]=i;
      eight_queen(now+1);
      row[i]=0;column[now]=0;rd[i+now]=0;ld[7+i-now]=0;
    }
  }

}
void reset(){
  for(int i=0;i<8;i++)row[i]=column[i]=rd[i]=ld[i]=0;
  for(int i=8;i<15;i++)rd[i]=ld[i]=0;
  path.resize(8);
  Ans.clear();
}
void compute(){
  reset();
  for(int i=0;i<8;i++){
    int now=0;
    path[now]=i;
    row[i]=1;column[0]=1;rd[i+0]=1;ld[7+i-0]=1;
    eight_queen(now+1);
    row[i]=0;column[0]=0;rd[i+0]=0;ld[7+i-0]=0;
  }
  //cout << Ans.size() << endl;
}

main(){
  compute();
}
