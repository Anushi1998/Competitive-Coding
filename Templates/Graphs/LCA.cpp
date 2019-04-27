int n;
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