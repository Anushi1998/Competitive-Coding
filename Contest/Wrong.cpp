#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define ii pair<int,int>

struct node{
    int val;
    node* left;
    node* right;
    node():val(0),left(NULL),right(NULL){};
    node(int v):val(v),left(NULL),right(NULL){};
};

int n;
ii a[N];
int b[N];
int l,r,v;
node* pers[N];

node* build(int i,int j,node* pre){
    if(i>r || j<l) return pre;
    if(i>=l && j<=r) return new node{v};
    int mid=(i+j)>>1;
    node* cur=new node();
    cur->left=build(i,mid,pre->left);
    cur->right=build(mid+1,j,pre->right);
    cur->val=cur->left->val+cur->right->val;
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

int query(int i,int j,node* pre, node* nex){
    if(i==j) return b[i];
    int mid=(i+j)>>1;
    if(nex->left->val - pre->left->val >=v) return query(i,mid,pre->left,nex->left);
    v-=(nex->left->val - pre->left->val);
    return query(mid+1,j,pre->right,nex->right);
}

int main(){
    int q;
    cin>>n>>q;
    pers[0]=init();
    for(int i=0;i<n;i++) {cin>>a[i].first; a[i].second=i;}

    sort(a,a+n);
    for(int i=0;i<n;i++) b[i]=a[i].first,a[i].first=i;
    sort(a,a+n,[](ii x,ii y){
        return x.second<y.second;
    });
    v=1;
    for(int i=0;i<n;i++) {
        l=r=a[i].first;
        pers[i+1]=build(0,n-1,pers[i]);
    }

    while(q--){
        cin>>l>>r>>v;
        cout<<endl<<query(0,n-1,pers[l-1],pers[r])<<endl;
    }

    return 0;
}
