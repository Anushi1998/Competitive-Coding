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

// unsigned int seed=random_device{}();
// mt19937 gen(seed);
// uniform_int_distribution<>dis(numeric_limits<int>::lowest(),std::numeric_limits<int>::max());

signed main(){
    srand(time(NULL));
    int n=100;

    fout<<n<<endl;
    
    for(int i=2;i<=n;i++){
        int p=rand()%(i-1);
        p++;
        fout<<p<<' ';
    }
    return 0;
}
