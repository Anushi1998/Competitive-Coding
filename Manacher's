#include <bits/stdc++.h>
using namespace std;

const int N=1000;
const int mod=1e9+7;

string Manacher(string s){
    int n=s.length();
    string _s="{";
    for(int i=0;i<n;i++) _s+=("#"+s.substr(i,1));_s+="#}";

    n=_s.length();
    int p[n+5],r=0,c=0;

    for(int i=1;i<n-1;i++){
        int j=c-(i-c);
        p[i]=max(0,min(r-i,p[j]));
        while(_s[i+1+p[i]]==_s[i-1-p[i]]) p[i]++;
        if(p[i]+i>r) c=i,r=i+p[i];
    }

    int maxlen=0,center=0;
    for(int i=1;i<n-1;i++)
        if(p[i]>maxlen) maxlen=p[i],center=i;

    return s.substr((center-1-maxlen)>>1,maxlen);
}

int main(){
    string h;
    cin>>h;
    cout<<Manacher(h);

    return 0;
}
