#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define ii pair<int,int>

std::vector<std::string> input;

int main(){
    int n,m;
    std::string a;
    
    cin>>n;
    for(int i=0;i<n;i++) { cin>>a; input.push_back(a); }

    sort(input.begin(), input.end());

    cin>>m;
    while(m--) {
        cin>>a;
        cout<<std::binary_search(input.begin(), input.end(), a)<<endl;
    }
    return 0;
}

