#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=25;
const int mod=1e9+7;

//Program

int n,m;
vector<int> tree[N];
int level[N],in[N];
vector<int> euler;
bitset<N> v;
int spt[M][(N<<2)];

void dfs(int id){
    in[id]=(int)euler.size(),v[id]=1;
    euler.push_back(id);
    for(auto &i:tree[id]) {
        if(!v[i]) level[i]=level[id]+1,dfs(i);
        euler.push_back(id);
    }
    euler.push_back(id);
}

void preLCA(){
    for(int i=0;i<euler.size();i++) spt[0][i]=euler[i];
    for(int j=1;(1<<j)<=euler.size();j++) for(int i=0;i+(1<<j)-1<euler.size();i++) {
            spt[j][i]=(level[spt[j-1][i]]<level[spt[j-1][i+(1<<(j-1))]])?spt[j-1][i]:spt[j-1][i+(1<<(j-1))];
        }
}

int LCA(int i,int j){
    i=in[i],j=in[j];if(i>j) swap(i,j);
    int k=log2(j-i+1.0);
    return (level[spt[k][i]]<level[spt[k][j-(1<<k)+1]])?spt[k][i]:spt[k][j-(1<<k)+1];
}

int root;
int sz[N];
//vector<int> centroidTree[N];
int centroidp[N];
int big;

int dfsC(int id,int p=-1){
    sz[id]=1;
    for(auto &i:tree[id])
        if(!v[i] && i!=p) sz[id]+=dfsC(i,id);
    return sz[id];
}

int centroid(int id,int p=-1){
    for(auto &i:tree[id])
        if(!v[i] && sz[i]+sz[i]>big && i!=p) return centroid(i,id);
    return id;
}

int centroidDecomp(int id){
    dfsC(id);
    big=sz[id];
    int ans=centroid(id);v[ans]=1;
    for(auto &i:tree[ans]) if(!v[i]) {
            int who=centroidDecomp(i);
//            centroidTree[who].push_back(ans);centroidTree[ans].push_back(who);
            centroidp[who]=ans;
        }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int x,y;
    int dist[N];

    cin>>n>>m;
    for(int i=1;i<n;i++) {
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1);preLCA();
    v.reset();
    big=n;
    root=centroidDecomp(1);

    for(int i=0;i<=n;i++) dist[i]=mod;

    {
        y=1;
        int who=y;dist[y]=0;
        while(who!=root){
            who=centroidp[who];
            dist[who]=min(dist[who],level[y]+level[who]-(level[LCA(y,who)]<<1));
        }
    }

    while(m--){
        cin>>x>>y;
        if(x==1){
            int who=y;dist[y]=0;
            while(who!=root){
                who=centroidp[who];
                dist[who]=min(dist[who],level[y]+level[who]-(level[LCA(y,who)]<<1));
            }
        }
        else{
            int ans=dist[y];
            int who=y;
            while(who!=root){
                who=centroidp[who];
                ans=min(ans,level[y]+level[who]-(level[LCA(y,who)]<<1)+dist[who]);
            }
            cout<<ans<<'\n';
        }
    }
}
