//Kruskal's Algorithm
#define ii pair<int,int>
vector<pair<int,ii> >edge;

int p[N];
int rank[N];

void UFDS(){
  for(int i=0;i<n;i++) p[i]=i,rank[i]=0;
}

int findSet(int x){
  return (x==p[x])?x:p[x]=findSet(p[x]);
}

void mergeSet(int x,int y){
  if(findSet(x)!=findSet(y)){
     x=findSet(x),y=findSet(y);
     if(rank[x]>rank[y]) p[y]=x;
     else p[x]=y,rank[x]+=(rank[x]==rank[y]);
  }
}

int cost=0;

void MST(){
  UFDS();
  sort(edge.begin(),edge.end());
  for(int i=0;i<edge.size();i++){
    ii who=edge.second;
    if(findSet(who.first)!=findSet(who.second)){
      cost+=edge.first;
      mergeSet(who.first,who.second);
    }
  }
}


//Prim's Algorithm
bitset<N> v;
priority_queue<ii,vector<ii>,greater<ii>()> pq;
int cost=0;

void process(int id){
  v[id]=1;
  for(auto &i:adj[id]){
    if(!v[i.first]) pq.push(ii{i.second,i.first});
  }
}

void MST(){
  process(0);
  while(!pq.empty()){
    ii who=pq.top();pq.pop();
    if(!v[who.second]) cost+=who.first,process(who.second);
  }
}
