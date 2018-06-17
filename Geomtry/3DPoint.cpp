//3肌傅のポイント房。
//vefiry はしてない。
//


class Point{
public:
  double x,y,z;
  double dist(){
    return sqrt(x*x+y*y+z*z);
  }
  Point operator+(Point a)const{
    return (Point){x+a.x,y+a.y,z+a.z};
  }
  Point operator-(Point a)const{
    return (Point){x-a.x,y-a.y,z-a.z};
  }
  Point operator*(double a)const{
    return (Point){a*x,a*y,a*z};
  }
  Point operator/(double a)const{
    return (Point){x/a,y/a,z/a};
  };
};

//Lib
double dot(Point A,Point B){
  return A.x*B.x + A.y*B.y + A.z*B.z;
}

//Lib
Point CircumCenter(Point A,Point B,Point C){
  Point ret;
  double a=(B-C).dist(),b=(C-A).dist(),c=(A-B).dist();
  double cosA=dot(B-A,C-A)/(b*c);
  double s=(c-b*cosA)/(2*c*(1-cosA*cosA));
  double t=(b-c*cosA)/(2*b*(1-cosA*cosA));
  ret=(B-A)*s+(C-A)*t+A;
  return ret;
}

//Lib
Point normal_vector(Point a,Point b){
  Point ret =(Point){a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};
  double len=ret.dist();
  ret=ret/len;
  return ret;
}
