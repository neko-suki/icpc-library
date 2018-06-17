//ローマ数字をintに変換する

#include<iostream>
using namespace std;



string convert(int num){
  string ret;
  while(num > 0){
    if ( num /1000 >0){
      ret+= string(num/1000,'M');
      num = num -(num/1000)*1000;
    }
    else if ( num/900 == 1){
      ret+="CM";
      num-=900;
    }else if ( 500 < num && num < 900){
      ret+='D'+string((num-500)/100,'C');
      num = num - ( (num)/100)*100;
    }else if ( num/500 == 1){
      ret+='D';
      num-=500;
    }else if ( num/400 == 1){
      ret+="CD";
      num-=400;
    }else if (num/100 > 0){
      ret+=string(num/100,'C');
      num = num- (num/100)*100;
    }else if ( num/90 == 1){
      ret+= "XC";
      num-=90;
    }else if ( 50 < num && num < 90){
      ret+= 'L'+string( (num-50)/10,'X');
      num= num- (num/10)*10;
    }else if ( num/50 == 1){
      ret+='L';
      num-=50;
    }else if ( num/40 == 1){
      ret+="XL";
      num-=40;
    }else if (9 < num && num<40){
      ret+= string(num/10,'X');
      num = num-(num/10)*10;
    }else if ( num== 9){
      ret+="IX";
      num=0;
    }else if ( 5<num && num < 9){
      ret+='V'+string((num-5),'I');;
      num=0;
    }else if ( num == 5){
      ret+='V';
      num=0;
    }else if (num == 4){
      ret += "IV";
      num=0;
    }else {
      ret+=string(num,'I');
      num=0;
    }
  }  
  return ret;
}


int convert2(string & temp){
  int point =0;
  int ret = 0;
  while(point < temp.size()){
    
    if ( temp[point] == 'M'){
	ret+=1000;
	point++;
    }else if ( temp[point] == 'C'){
      if ( point +1 < temp.size() && temp[point+1] =='M'){
	ret+=900;
	point+=2;
      }else if (point+1 < temp.size() && temp[point+1]=='D'){
	ret+=400;
	point+=2;
      }else {
	ret+=100;
	point++;
      }
    }else if ( temp[point] == 'D'){
      ret+=500;
      point++;
    }else if ( temp[point] == 'X'){
      if ( point+1 < temp.size() && temp[point+1] =='C'){
	ret+=90;
	point+=2;
      }else if ( point+1 < temp.size() && temp[point+1] == 'L'){
	ret+=40;
	point+=2;
      }else {
	ret+=10;
	point++;	
      }      
    }else if (temp[point] == 'L'){
      ret+=50;
      point++;
    }else if (temp[point] == 'V'){
      ret+=5;
      point++;
    }else if ( temp[point] =='I'){
      if ( point+1 < temp.size() && temp[point+1] =='X'){
	ret+=9;
	point+=2;	
      }else if (point+1 < temp.size() && temp[point+1] == 'V'){
	ret+=4;
	point+=2;
      }else {
	ret+=1;
	point++;
      }
    }
    
    
  }

  return ret;
}

main(){
  char data[1000];
  //  while(fgets(data,1000,stdin)){
  while(scanf("%s",data) != EOF){
    
    
    if ( isdigit(data[0])){
      int num ;
      sscanf(data,"%d",&num);
      cout << convert(num) << endl;
    }else {
      string inp(data);
      cout<< convert2(inp) << endl;
    }

  }
  return false;
}
