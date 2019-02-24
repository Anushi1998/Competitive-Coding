#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define int long long

#define ii pair<int,int>
#define ll pair<long long,long long>

struct node{
    long long a;
    long long b;
    node* left;
    node* right;
    node():a(0),b(0),left(NULL),right(NULL){};
    node(int _a,int _b):a(_a),b(_b),left(NULL),right(NULL){};
    void sum(){
        a=left->a+right->a;
        b=left->b+right->b;
    }
};


int n;
int a[N],b[N];
pair<double,int> rat[N];
int l,r;
ii v;
node* pers[N];

node* build(int i,int j,node* pre){
    if(i>r || j<l) return pre;
    if(i>=l && j<=r) return new node{v.first,v.second};
    int mid=(i+j)>>1;
    node* cur=new node();
    cur->left=build(i,mid,pre->left);
    cur->right=build(mid+1,j,pre->right);
    cur->sum();
    return cur;
}

node* init(int i=0,int j=n-1){
    if(i==j) return new node();
    int mid=(i+j)>>1;
    node* cur=new node();
    cur->left=init(i,mid);
    cur->right=init(mid+1,j);
    return cur;
}

ll query(int i,int j,node* pre, node* nex){
    if(i>r || j<l) return {0,0};
    if(i>=l && j<=r) return {nex->a-pre->a,nex->b-pre->b};
    int mid=(i+j)>>1;
    ll L=query(i,mid,pre->left,nex->left);
    ll R=query(mid+1,j,pre->right,nex->right);
    return {L.first+R.first,L.second+R.second};
}

signed main(){
    int q,c,d;
    cin>>n;
    pers[0]=init();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    cin>>q;
    for(int i=1;i<=n;i++)
        rat[i].first=(b[i]==0)?mod:(double)a[i]/b[i],rat[i].second=i;
    sort(rat+1,rat+n+1,[](pair<double,int> i,pair<double,int> j){
        return i.first<j.first;
    });
    rat[0]={0.0,0};
    for(int i=1;i<=n;i++) {
        l=r=rat[i].second;
        v.first=a[l],v.second=b[l];
        pers[i]=build(1,n,pers[i-1]);
    }

    while(q--){
        cin>>l>>r>>c>>d;
        double ra=(d==0)?mod:(double)d/c;
        int L=lower_bound(rat,rat+n+1,make_pair(ra,0LL))-rat;
        ll R=query(1,n,pers[L-1],pers[n]);
        long long ans=(R.first*1LL*c)-(R.second*1LL*d);
        cout<<ans<<endl;
    }

    return 0;
}
