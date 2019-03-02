#include<bits/stdc++.h>
using namespace std;

const int N=10010;
const int mod=1e9+7;

int add(int a,int b){int res=(a+b)%mod;return (res<0)?res+mod:res;}
int mul(int a,int b){int res=(a*1LL*b)%mod;return (res<0)?res+mod:res;}

int n;
int a[N];
int l,r;
vector<int> st[4*N];

void build(int p=1,int i=0,int j=n-1){
    if(i==j){
        cout<<__builtin_popcount(a[i]);
        st[p][__builtin_popcount(a[i])]++;
        return;
    }
    int mid=(i+j)>>1;
    build(p<<1,i,mid);build(p<<1|1,mid+1,j);
    for(int ii=0;ii<32;ii++) st[p][ii]=st[p<<1][ii]+st[p<<1|1][ii];
}

void upd(int p=1,int i=0,int j=n-1){
    if(i>l || j<l) return;
    if(i==j && i==l){
        st[p][__builtin_popcount(a[l])]--;
        a[l]=r;
        st[p][__builtin_popcount(a[i])]++;
        return;
    }
    int mid=(i+j)>>1;
    upd(p<<1,i,mid);upd(p<<1,mid+1,j);
    for(int ii=0;ii<32;ii++) st[p][ii]=st[p<<1][ii]+st[p<<1|1][ii];
}

vector<int> query(int p=1,int i=0,int j=n-1){
    if(i>r || j<l) return vector<int>(32,0);
    if(i>=l && j<=r) return st[p];
    int mid=(i+j)>>1;
    auto as=query(p>>1,i,mid);
    auto ass=query(p<<1|1,mid+1,j);
    vector<int> ans(32,0);
    for(int ii=0;ii<32;ii++) st[p][ii]=as[ii]+ass[ii];
}

int main()
{
    for(int i=0;i<4*N;i++) st[i].resize(32,0);

    int q,ty;
    cin>>n>>q;

    for(int i=0;i<n;i++) cin>>a[i];
    build();

    while(q--){
        cin>>ty>>l>>r;
        if(ty==1){
            --l;
            upd();
        }
        else{
            --l,--r;
            vector<int> f=query();
            int ans=1;
            for(int i=0;i<31;i++)
                ans=mul(ans,f[i]);
            cout<<ans<<'\n';
        }
    }

}