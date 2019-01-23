//0-Unvisited 1-Partially Visited 2-CompleteVisited
int v[N];

void EdgeCheck(int id,int p){
  v[id]=1;
  for(auto &i:adj[id]){
    if(v[id]==0){
      //Forward Edge
      EdgeCheck(i,id);
    }
    else if(v[id]==1 && i!=p){
      //Back Edge
    }
    else if(v[id]==2){
      //Forward edge
    }
    v[id]=2;
  }
}
