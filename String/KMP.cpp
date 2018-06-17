//KMP

#include<iostream>
#include<string>

using namespace std;

int KMP(string text,string word){
  // maketable for search word
  int table[word.length()];
  int i=2,j=0;//i:searching word j:backtracking point
  table[0]=-1;//0良くわからない？
  table[1]=0;//１文字目でマッチングしなかったっ場合には0文字目からやり直す。
  while(i < word.length()){//make table
    if ( word[i-1] == word[j]){
      table[i]=j+1;
      i++;
      j++;
    }else if ( j > 0){
      j = table[j];
    }else {
      table[i]=0;
      i++;
    }
  }
  //the main part of KMP algorithm
  int pos;//text内でwordが見つかった位置。先頭文字は0番目
  int m=0;//text内の現在位置
  i = 0;//word内の現在位置
  while(m+i <text.length()){
    if (word[i] == text[m+i]){
      i++;
      if ( i == word.length())return m;
    }else {
      m = m+i-table[i];
      if (i > 0)i = table[i];
    }
  }
  return text.length();
}





main(){

  
  cout << KMP("ABC ABCDAB ABCDABCDABDE","ABCDABD")<<endl;
  return 0;
}
