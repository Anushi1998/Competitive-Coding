vector<int> topo;
bitset<N> v;

//Using DFS
void dfs(int id){
  v[id]=1;
  for(auto &i:adj[id]) if(!v[i]) dfs(i);
  topo.push_back(id);
}
reverse(topo.begin(),topo.end());

int in[N]; //initalize it in main
void bfs(){
  queue<int> q;
  for(int i=0;i<n;i++) if(!in[i]) q.push(i);
  while(!q.empty()){
    int who=q.front();q.pop();
    topo.push(who);
    for(auto &j:adj[who]) if(!(--in[j])) q.push(j);
  }
}
