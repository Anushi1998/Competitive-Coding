#include<bits/stdc++.h>
using namespace std;

const int N=500010;
const int mod=1e9+7;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define int long long
#define ii pair<int,int>

int n,k;
int a[N];

int dp[1000][1000];
unordered_set<int> all[1000][1000];

#define dpp dp[id][where]

int solve(int id, int where) {
    if(id==n) return 0;
    if(dpp!=-1) return dpp;
    dpp=solve(id+1, where+1);
    for(const auto x: all[id+1][where]) all[id][where].insert(x);
    if(a[id]==where) {
        all[id].insert(id+1);
        for(const auto x: all[id]) {
            cout<<id<<' '<<x<<endl;
            dpp=max(dpp, solve(x+1, where)+1);
        }
    }
    return dpp;
}

void contest() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp, -1, sizeof dp);
    for(int i=1;i<=n;i++) all[i].clear();
    cout<<solve(1,1)<<endl;
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