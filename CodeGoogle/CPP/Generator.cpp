#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>

using namespace std;
ofstream fout ("..//TXT//Test.txt");
const int mod=1e9+7;
int val=50;
const long long ll=1000000000000000001LL;
int operations=1e8;
const int N=1000;

unsigned long long llrand() {
    unsigned long long r = 0;
    for (int i = 0; i < 5; ++i)
        r = (r << 15) | (rand() & 0x7FFF);
    return (r % mod)+1;
}

unsigned int seed=random_device{}();
mt19937 gen(seed);
uniform_int_distribution<>dis(numeric_limits<int>::lowest(),std::numeric_limits<int>::max());

#define int long long

int t;
int n;
int a[N];
int q,p;

signed main(){
    srand(time(0));
    t=1;
    fout<<t<<endl;
    while(t--){
        n=10;
        q=rand()%10000+1;
        p=rand()%10000;
        while(p>=q) p=rand()%10000;
        fout<<n<<' '<<p<<' '<<q<<endl;
        for(int i=0;i<n;i++)
        fout<<rand()%100+1<<' ';
        fout<<endl;
    }
    return 0;
}
