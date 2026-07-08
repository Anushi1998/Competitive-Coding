#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>

using namespace std;
ofstream fout ("..//TXT//Test.txt");
const int mod=1e9+7;
const long long ll=1000000000000000001LL;
int operations=1e8;
const int N=100001;

unsigned long long llrand() {
    unsigned long long r = 0;
    for (int i = 0; i < 5; ++i)
        r = (r << 15) | (rand() & 0x7FFF);
    return (r % mod)+1;
}

unsigned int seed=random_device{}();
mt19937 gen(seed);
uniform_int_distribution<>dis(numeric_limits<int>::lowest(),std::numeric_limits<int>::max());
uniform_int_distribution<>dis2(1,100);

int p[N];
vector<int> levelTree[N];
int maxLevel=0;

void generateTree(int n) {
    int level=0;
    maxLevel=1;
    levelTree[0].clear();levelTree[1].clear();
    levelTree[level].push_back(1);
    for(int i=2;i<=n;i++) {
        level=(rand()%maxLevel)+1;
        if(level==maxLevel) {
            maxLevel++;
            levelTree[maxLevel].clear();
        }
        levelTree[level].push_back(i);
        int who=rand()%levelTree[level-1].size();
        p[i]=levelTree[level-1][who];
    }
}

signed main(){
    srand(time(NULL));
    int t=10;
    int n,k;

    fout<<t<<endl;

    while(t--) {
        int n=5;
    
        fout<<n<<endl;
    
        for(int i=1;i<=n;i++) {
            int r=rand()%7;
            fout<<r<<' ';
        }
        fout<<endl;
    }

    return 0;
}
