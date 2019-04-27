#include<bits/stdc++.h>
using namespace std;

const int N=500010;
const int M=25;
const int mod=1e9+7;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define ii pair<int,int>

int n;
int p[N];
vector<int> tree[N];
vector<int> lev[N];

vector<int> nf;
vector<pair<int,int> >f;

int level[N],in[N];
vector<int> euler;
bitset<N> v;
int spt[M][3000000];

void dfs(int id){
    in[id]=(int)euler.size(),v[id]=1;
    lev[level[id]].push_back(id);
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
    int k=1;
    while((1LL<<k) <= (j-i+1)) k++;k--;
    // log2(j-i+1.0);
    return (level[spt[k][i]]<level[spt[k][j-(1<<k)+1]])?spt[k][i]:spt[k][j-(1<<k)+1];
}

bitset<N> ok;
#define iii pair<int,ii> 

int main(){
    cin>>n;
    for(int i=2;i<=n;i++) {
        cin>>p[i];
        tree[p[i]].push_back(i);
    }
    dfs(1);
    preLCA();
    
    for(int i=0;i<N;i++){
        vector<iii> xd;
        for(int j=0;j<lev[i].size();j++){
            for(int k=j+1;k<lev[i].size();k++){
                xd.push_back({level[LCA(lev[i][j],lev[i][k])],{lev[i][j],lev[i][k]}});
            }
        }
        sort(xd.begin(),xd.end(),[](iii aa,iii bb){
            return aa.first<bb.first;
        });

        while(!xd.empty()){
            iii oo=xd.back();xd.pop_back();
            if(ok[oo.second.first] || ok[oo.second.second]) continue;
            f.push_back({oo.second.first,oo.second.second});
            ok[oo.second.first]=ok[oo.second.second]=1;
        }

        for(auto j:lev[i]){
            if(!ok[j]) nf.push_back({j});
        }
    }
    sort(nf.begin(),nf.end());
    sort(f.begin(),f.end());
    cout<<nf.size()<<endl;
    // for(auto i:nf) cout<<i<<' ';cout<<endl;
    cout<<f.size()<<endl;
    // for(auto i:f) cout<<i.first<<' '<<i.second<<endl;
    
    return 0;
}
