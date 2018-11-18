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

template<
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type
>
class point{
public:
    T x,y,z;
    //@constructors
    point(){x=y=z=0;};
    point(T _x,T _y,T _z): x(_x), y(_y), z(_z){};
    point(T _x,T _y): x(_x), y(_y){z=0;};

    //@Opertaor-Overloading
    bool operator == (point other) const{return (fabs(x-other.x)<eps && fabs(y-other.y)<eps && fabs(z-other.z)<eps);}
    bool operator < (point other) const {
        if(fabs(x-other.x)>eps) return x<other.x;
        if(fabs(y-other.y)>eps) return y<other.y;
        return z<other.z;
    }

    //@Methods
    double inline dist(point other){double _x=x-other.x,_y=y-other.y;return sqrt((x*x)+(y*y));}
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

    //@operator-overloading
    bool operator < (line l) const{return slope()<l.slope();}
    bool operator == (line l) const{return isParallel(l) && fabs(l.c-c)<eps;}

    //@utility function
    void print(){
        if(fabs(b)<eps) {cout<<"Line x="<<(-c/a)<<endl;return;}
        cout<<"Line : y="<<(-a/b)<<"x+"<<(-c/b)<<endl;
    }
};

int main(){
    point<int> p1;
    line l(p1,p1);
}
