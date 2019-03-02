#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define mod 1000000007

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

int power(int x,int y){
    int res=1; //x^y
    while(y){
        if(y&1) res=mul(res,x);
        x=mul(x,x);
        y=y>>1;
    }
    return res;
}

int fact[N],invfact[N];

int C(int n,int r){
	return mul(mul(fact[n],invfact[r]),invfact[n-r]);
}

void _build(){
	fact[0]=1,invfact[0]=1;
	for(int i=1;i<N;i++) 
		fact[i]=mul(fact[i-1],i),invfact[i]=power(fact[i],mod-2);
}

int main(){
	_build();
	cout<<C(5,3);
}
