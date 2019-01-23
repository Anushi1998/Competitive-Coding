int dfsNum[N],dfsMin[N];
bitset<N> v,ap;

void dfs(int id,int p){
  dfsMin[id]=dfsNum[id]=((p>0)?dfsNum[p]:0)+1;
  for(auto &i:adj[id]){
    if(i==p) continue;
    if(!v[i]) dfs(i,id);
    if(dfsMin[i]>dfsNum[id]) {
      //Bridge id->i
    }
    if(dfsMin[i]>=dfsNum[id]) ap[id]=1;
    dfsMin[id]=min(dfsMin[id],dfsMin[i]);
  }
}

for(int i=0;i<n;i++)
  if(!v[i]){
    dfs(i,-1);
    ap[i]=(adj[i].size()>1);
  }
