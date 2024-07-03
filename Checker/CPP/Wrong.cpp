#include<bits/stdc++.h>
using namespace std;

const int N=500010;
const int mod=1e9+7;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define ii pair<int,int>
#define int long long

int n,k;
int a[N],b[N],c[N];
string s;

void contest() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    b[n-1]=a[n-1];
    c[n-1]=0;
    for(int i=n-2;i>=0;i--) {
        if(a[i]>a[i+1]) {
            int cover=a[i]-a[i+1];
            b[i]=cover+b[i+1]+1-min(b[i+1]-a[i+1]+1,cover);
            c[i]=max(0LL,c[i+1]-cover);
        } else {
            b[i]=b[i+1]+1;
            c[i]=c[i+1]+1;
        }
    }
    // for(int i=0;i<n;i++) cout<<b[i]<<' ';cout<<endl;
    // for(int i=0;i<n;i++) cout<<c[i]<<' ';
    cout<<b[0]<<endl;
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        // cout<<"=========================";
        contest();
    }
    return 0;
}
// 10
// =========================5
// 8 10 7 8 6 
// 12 11 9 8 6 
// 1 0 1 0 0 12