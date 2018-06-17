//サイコロ
//accepted by AOIJ1253,1259

#define rotate_swap(x,a,b,c,d) swap(x.a,x.b);swap(x.b,x.c);swap(x.c,x.d);

class Dice{
public:
  int top,front,right,left,back,bottom;
};

void rotate_r(Dice &x){
  rotate_swap(x,top,left,bottom,right);
}

void rotate_l(Dice &x){
  rotate_swap(x,top,right,bottom,left);
}

void rotate_f(Dice &x){
  rotate_swap(x,top,back,bottom,front);
}

void rotate_b(Dice &x){
  rotate_swap(x,top,front,bottom,back);
}

void rotate_cw(Dice &x){
  rotate_swap(x,back,left,front,right);
}

void rotate_ccw(Dice &x){
  rotate_swap(x,back,right,front,left);
}

Dice data[24];

void generate_all(Dice x){
  rep(i,6){
    rep(j,4){
      data[i*4+j]=x;
      rotate_cw(x);
    }
    if (i%2 == 0)rotate_r(x);
    else rotate_f(x);
  }
}
