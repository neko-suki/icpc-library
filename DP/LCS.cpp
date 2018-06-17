//LCS


#include<iostream>
#include<string>
#include<stack>
using namespace std;

#define LENGTH 100

int path[LENGTH][LENGTH];


void makepath(int pathdata){
  switch(pathdata){
  case 0:

    break;
  case 1:
    break;
  case 2:
    break;
  }
}



int LCS(string data1,string data2){
  int data[data1.length()+1][data2.length()+1];
  for(int i=0;i<data1.length();i++)data[i][0]=0;
  for(int i=0;i<data2.length();i++)data[0][i]=0;

  for(int i=1;i<=data1.length();i++){
    for(int j=1;j<data2.length();j++){
      if ( data1.at(i-1) == data2.at(j-1)){
	path[j][i]=0;
	data[i][j] = data[i-1][j-1]+1;
      }
      else if (data[i][j-1] > data[i-1][j]){
	path[i][j]=1;
	data[i][j]=data[i][j-1];
      } 
      else {
	path[i][j]=2;
	data[i][j]=data[i-1][j];
      }
    }
  }
	
  return data[data1.length()][data2.length()];



}



main(){
  string data1,data2;
  getline(cin,data1);
  getline(cin,data2);
  int count = LCS(data1,data2);
  cout << count << endl;

}
