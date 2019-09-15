template<int sz> struct UF{
  int p[sz+2],rank[sz+2],cnt[sz+2],SZ;
  UF() { for(int i=0;i<sz;i++) p[i]=i,cnt[i]=1,rank[i]=0;SZ=sz;}
  void init(int size) { for(int i=0;i<size;i++) p[i]=i,cnt[i]=1,rank[i]=0;SZ=size;}
  int operator[](int x) {return (p[x]==x)?x:p[x]=operator[](p[x]);}
  int size() {return SZ;}
  void operator()(int x,int y) {
    if((x=operator[](x))!=(y=operator[](y))){
      cnt[y]=cnt[x]=cnt[x]+cnt[y];
      if(rank[x]>rank[y]) p[x]=y;
      else p[y]=x,rank[x]+=(rank[x]==rank[y]);
      SZ--;
    }
  }
};

Problem 1 : https://codeforces.com/contest/1108/submission/48881492 
