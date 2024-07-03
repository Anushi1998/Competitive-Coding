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
    int ans=0;
    while(true) {
      bool ok=false;
      for(int i=0;i<n-1;i++) {
        if(a[i]>a[i+1]) {
          a[i]--;
          ok=true;
        }
      }
      if(a[n-1]>0) {
        a[n-1]--;
        ok=true;
      }
      if(!ok) {
        cout<<ans<<endl;
        return;
      }
      ans++;
    }
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