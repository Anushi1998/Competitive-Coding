vector<int> adj[N];
int d[N];  //for(int i=0;i<n;i++) d[i]=mod;

void bfs(int id){
  queue<int> q;
  q.push(id);
  while(!q.empty()){
    id=q.top();q.pop();
    for(auto &i:adj[id])
      if(d[i]==mod){
        d[i]=d[id]+1; //Change here for weighted Graph
        q.push(i);
      }
  }
}
