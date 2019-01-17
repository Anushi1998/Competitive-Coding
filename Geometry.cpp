#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;
const double inf=mod*1.0*mod;
const double eps=1e-9;
const double pi=3.141592653589793238462643383279502884197169399375105820974944;

int inline add(int a,int b){int res=(a+b)%mod;return (res<0)?res+mod:res;}
int inline mul(int a,int b){int res=(a*1LL*b)%mod;return (res<0)?res+mod:res;}
double inline deg(double theta){return theta*180/pi;}
double inline rad(double theta){return theta*pi/180;}
int inline sumAnglesInPolygon(int n,int deg=1){return (deg)?((n-2)*180):rad(((n-2)*180));}

template<
        typename T,
        typename = typename enable_if<is_arithmetic<T>::value, T>::type
>
class point{
public:
    T x,y,z;
    //@constructors
    point(){x=y=z=0;};
    point(T _x,T _y,T _z=0): x(_x), y(_y), z(_z){};

    //@Opertaor-Overloading
    bool operator == (point other) const{return (fabs(x-other.x)<eps && fabs(y-other.y)<eps && fabs(z-other.z)<eps);}
    bool operator < (point other) const {
        if(fabs(x-other.x)>eps) return x<other.x;
        if(fabs(y-other.y)>eps) return y<other.y;
        return z<other.z;
    }

    //@Methods
    double inline dist(point other){
        double _x=x-other.x,_y=y-other.y,_z=z-other.z;return sqrt((_x*_x)+(_y*_y)+(_z*_z));}
    point rotate(double theta){return point(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));}

    //@Utilty Functions
    void print(){cout<<"Point :"<<x<<" "<<y<<" "<<z<<endl;}
};

class line{
public:
    double a,b,c;   //ax+by+c=0;

    //@constructors
    line(){a=b=c=0.0;};
    line(double _a,double _b,double _c):a(_a/_b),b(1.0),c(_c/_b){};
    line(double m,double c):a((m<inf)?-m:1.0),b(m<inf),c(-c){};
    template<typename T> line(point<T> &p1,point<T> &p2){
        if(fabs(p1.x-p2.x)<eps) a=1.0,b=0.0,c=-p1.x;
        else {
            a=(double)(p2.y-p1.y)/(p1.x-p2.x);
            b=1.0;
            c=-(a*p1.x)-p1.y;
        }
    }

    //@methods
    double inline slope() const{return (fabs(b)<eps)?inf:(-a/b);}
    double inline y_intercept() const{return (fabs(b)<eps)?inf:(-c/b);}
    double inline x_intercept() const{return (fabs(a)<eps)?inf:(-c/b);}
    bool inline isParallel(line l) const{return (fabs(l.a-a)<eps && fabs(l.b-b)<eps);}
    bool inline isPerpendicular(line l) const{return fabs(slope()*l.slope()+1)<eps;}
    //https://math.stackexchange.com/questions/270767/find-intersection-of-two-3d-lines
    bool isIntersect(line l,point<double> &where=*(new point<double> ())){
        if(isParallel(l)) {where.x=inf,where.y=inf,where.z=inf;return false;}
        where.x=(c*l.b - l.c*b)/(b*l.a - a*l.b);
        where.y=(fabs(b)>eps)?-(a*where.x + c):-(l.a*where.x + l.c);
        return true;
    }

    //@operator-overloading
    bool operator < (line l) const{return slope()<l.slope();}
    bool operator == (line l) const{return isParallel(l) && fabs(l.c-c)<eps;}

    //@utility function
    void print(){
        if(fabs(b)<eps) {cout<<"Line x="<<(-c/a)<<endl;return;}
        cout<<"Line : y="<<(-a/b)<<"x+"<<(-c/b)<<endl;
    }
};

template<
        typename T,
        typename = typename enable_if<is_arithmetic<T>::value, T>::type
>
class Vector{
public:
     T x,y,z; //xî+yj+zk

     //@constructors
     Vector():x(0),y(0),z(0){};
     Vector(T _x,T _y,T _z=0):x(_x),y(_y),z(_z){};
     template<typename TT> Vector(point<TT> a,point<TT> b):x(a.x-b.x),y(a.y-b.y),z(a.z-b.z){};

     //@methods
     void scale(int k){x*=k,y*=k,z*=k;}
     double mag(){return sqrt((x*x)+(y*y)+(z*z));}
     T dot(Vector other) {return (x*other.x)+(y*other.y)+(z*other.z);}
     Vector cross(Vector other){return new Vector(y*other.z - z*other.y,z*other.x - x*other.z,x*other.y - y*other.x);}

}

class Circle{
public:
    point<double> Centre;
    double r;

    //@constructors
    Circle():Centre(),r(0){};
    Circle(double _r,point<double> x):Centre(x),r(_r){};

    //@methods
    double pointFromCircle(point p){
        return ((p.x-Centre.x)*(p.x-Centre.x) + (p.y-Centre.y)*(p.y-Centre.y))<(r*r)?0:
               ((p.x-Centre.x)*(p.x-Centre.x) + (p.y-Centre.y)*(p.y-Centre.y))==(r*r)?1:2; //Inside-Border-Outside
    }
    double circumference(){return 2.0*pi*r;}
    double area(){return pi*r*r;}
};
