int dfsNum[N],dfsMin[N];
vector<vector<int> >SCC;
bitset<N> v;
vector<int> cur;
int counter;

void tarjanSCC(int id,int p){
  dfsMin[id]=dfsNum[id]=counter++;
  v[id]=1;
  cur.push_back(id);

  for(auto &i:adj[id]){
    if(!v[i]) tarjanSCC(i);
    dfsMin[id]=min(dfsMin[id],dfsMin[i]);
  }

  if(dfsMin[id]==dfsNum[id]){
    SCC.push_back(vector<int>);
    while(true) {
      int who=cur.back();cur.pop_back();v[who]=0;
      SCC.back().push_back(who);
      if(who==id) break;
    }
  }
}


for(int i=0;i<n;i++) if(!v[i]) tarjanSCC(i);
