#include<bits/stdc++.h>
using namespace std;

const int N=500010;
const int mod=1e9+7;
const int atcoderMod=998244353;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define ii pair<int,int>

int n,k;
int a[N],b[N];
string s;

void contest() {
    long long l,r;
    int bits=0;
    for(int i=0;i<64;i++) {
        if(((l>>i)&1) == 0 && ((r>>i)&1) == 1) {bits++;}
        else break;
    }
    cout<<(1LL<<bits)-1<<endl;
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        cout<<"=========================";
        contest();
    }
    return 0;
}