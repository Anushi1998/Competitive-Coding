#include<bits/stdc++.h>


namespace String{
    namespace{
        const int N=100010;
    }
    void kmpPre(std::string const&p, int* b) {
        int i=0,j=-1;b[0]=-1;
        while(i<p.length()){
            while(j>=0 && p[i]!=p[j]) j=b[j];b[++i]=++j;}
    }

    std::vector<int> kmpSearch(std::string const&t, std::string const& p) {
        int *b=new int(p.length()+2);
        int i=0,j=0;std::vector<int> ans;
        kmpPre(p,b);
        while(i<t.length()){
            while(j>=0 && t[i]!=p[j]) j=b[j];i++,j++;
            if(j==p.length()) {
                ans.push_back(i-j);
                j=b[j];
        }}
    }
    
    std::string Manacher(std::string const& s){
        int n=s.length();
        std::string _s="{";
        for(int i=0;i<n;i++) _s+=("#"+s.substr(i,1));_s+="#}";

        n=_s.length();
        int p[n+5],r=0,c=0;

        for(int i=1;i<n-1;i++){
            int j=c-(i-c);
            p[i]=std::max(0,std::min(r-i,p[j]));
            while(_s[i+1+p[i]]==_s[i-1-p[i]]) p[i]++;
            if(p[i]+i>r) c=i,r=i+p[i];
        }

        int maxlen=0,center=0;
        for(int i=1;i<n-1;i++)
            if(p[i]>maxlen) maxlen=p[i],center=i;

        return s.substr((center-1-maxlen)>>1,maxlen);
    }
}
