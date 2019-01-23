vector<int> adj[N];
bitset<N> v;

void dfs(int id){
  v[id]=1;
  for(auto &i:adj[id]) if(!v[i]) dfs(i);
}
