#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;

int add(int a,int b){int res=(a+b)%mod;return (res<0)?res+mod:res;}
int mul(int a,int b){int res=(a*1LL*b)%mod;return (res<0)?res+mod:res;}

int x,y,d;

void euclid(int a,int b){
    if(!b){x=1,y=0,d=a;return;}
    euclid(b,a%b);
    int _x=y,_y=x-y*(a/b);x=_x,y=_y;
}

int main(){
    euclid(25,18);
    cout<<"("<<x<<")25 + ("<<y<<")18 = "<<d<<endl;
    return 0;
}
