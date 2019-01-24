#define ii pair<int,int>
vector<pair<int,ii> >edge;
int n,m;
int p[N];
int Rank[N];

void UFDS(){
    for(int i=0;i<n;i++) p[i]=i,Rank[i]=0;
}

int findSet(int x){
    return (x==p[x])?x:p[x]=findSet(p[x]);
}

void mergeSet(int x,int y){
    if(findSet(x)!=findSet(y)){
        x=findSet(x),y=findSet(y);
        if(Rank[x]>Rank[y]) p[y]=x;
        else p[x]=y,Rank[x]+=(Rank[x]==Rank[y]);
    }
}

int cost=0;

void MST(){
    UFDS();
    sort(edge.begin(),edge.end());
    for(int i=0;i<edge.size();i++){
        ii who=edge[i].second;
        if(findSet(who.first)!=findSet(who.second)){
            cost+=edge[i].first;
            mergeSet(who.first,who.second);
        }
    }
}
