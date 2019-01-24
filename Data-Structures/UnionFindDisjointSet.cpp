template<int sz> struct UF{
  int p[sz+2],rank[sz+2],cnt[sz+2];
  UF() { for(int i=0;i<sz;i++) p[i]=i,cnt[i]=1,rank[i]=0;}
  void init() { for(int i=0;i<sz;i++) p[i]=i,cnt[i]=1,rank[i]=0; }
  int operator[](int x) {return (p[x]==x)?x:p[x]=operator[](p[x]);}
  void operator()(int x,int y) {
    if((x=operator[](x))!=(y=operator[](y))){
      cnt[y]=cnt[x]=cnt[x]+cnt[y];
      if(rank[x]>rank[y]) p[x]=y;
      else p[y]=x,rank[x]+=(rank[x]==rank[y]);
    }
  }
};

Problem 1 : https://codeforces.com/contest/1108/submission/48881492 
