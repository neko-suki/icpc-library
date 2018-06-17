//未verify
//ABCの角度を求める。
double angle(P a,P b,P c){
 return arg((a-b)/(c-b));
}
//AOBの角度を求める
//AOJ 2167 find point
P rot(P a,P b){
 return arg(b*conj(a));
}
