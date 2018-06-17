//AC rose2113
P mapping(P a,P b){//mapping b to a
  double tmp = dot(a,b);
  tmp/=abs(a);
  return a/abs(a)*tmp;
}
