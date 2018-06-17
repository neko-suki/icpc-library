//有理数型

class Q{
public:
  ll u,v;// u/v
  Q():u(0),v(1){}
  Q(ll tu,ll tv):u(tu),v(tv){
    if (tu == 0){
      v=1;
      return;
    }
    if (v < 0){
      v*=-1;
      u*=-1;
    }
    ll g = gcd(u>0?u:-u,v);
    u/=g;
    v/=g;
  };
  Q operator+(const Q a)const{
    ll tu,tv;
    tv=v*a.v;
    tu=u*a.v + a.u*v;
    return Q(tu,tv);
  }
  Q operator-(const Q a)const{
    ll tu,tv;
    tv=v*a.v;
    tu=u*a.v-a.u*v;
    return Q(tu,tv);
  }
  Q operator*(const Q a)const{
    ll tu,tv;
    tv=v*a.v;
    tu=u*a.u;
    return Q(tu,tv);
  }
  Q operator/(const Q a)const{
    ll tu,tv;
    tv=v*a.u;
    tu=u*a.v;
    return Q(tu,tv);
  }
  ll myabs(){
    return u>0?u:-u;
  }
};
