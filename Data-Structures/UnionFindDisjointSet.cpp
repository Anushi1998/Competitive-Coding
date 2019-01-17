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
   
Problem 1: https://codeforces.com/contest/500/submission/48393234
