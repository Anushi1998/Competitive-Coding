#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define ii pair<int,int>

int n;
int aa[N],bb[N],cc[N],dd[N];
int a,b,c,d;
vector<int> ab,cd;


int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>aa[i]>>bb[i]>>cc[i]>>dd[i];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            ab.push_back(aa[i]+bb[j]);
            cd.push_back(cc[i]+dd[j]);
        }
    }

    sort(ab.begin(),ab.end());
    sort(cd.begin(),cd.end());

    int ans=0;

    for(int i=0;i<ab.size();i++){
        ans+=upper_bound(cd.begin(),cd.end(),-ab[i])-lower_bound(cd.begin(),cd.end(),-ab[i]);
    }

    cout<<ans;
    return 0;
}
