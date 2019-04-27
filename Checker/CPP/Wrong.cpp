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

int main(){
    cin>>n;
    for(int i=2;i<=n;i++) {
        cin>>p[i];
        tree[p[i]].push_back(i);
    }
    dfs(1);
    preLCA();
    
    for(int i=0;i<N;i++){
        while(lev[i].size()>2){
            int _1=lev[i].back();lev[i].pop_back();
            int _2=lev[i].back();lev[i].pop_back();
            int _3=lev[i].back();lev[i].pop_back();
            
            if(level[LCA(_1,_2)]>level[LCA(_2,_3)]){
                lev[i].push_back(_3);
                f.push_back({_2,_1});
            }
            else if(level[LCA(_1,_2)]==level[LCA(_2,_3)]){
                if(LCA(_1,_2)!=LCA(_2,_3)) throw SIGSEGV;
                lev[i].push_back(_3);
                f.push_back({_2,_1});
            }
            else{
                lev[i].push_back(_1);
                f.push_back({_3,_2});
            }
        }
        if(lev[i].size()==1){
            nf.push_back(lev[i][0]);
        }
        else if(lev[i].size()==2){
            f.push_back({lev[i][0],lev[i][1]});
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