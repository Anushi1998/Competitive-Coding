#include <bits/stdc++.h>
using namespace std;

#define N 100010

//change seive size change no. of primes created
const int seive_size=N;
vector<int> primes;
bitset<seive_size> bs;
void seive(){
  bs.set();
  for(int i=2;i<seive_size;i++)
    if(bs[i]){
      for(long long int j=i*1LL*i;j<seive_size;j++)
        bs[j]=0;
      primes.push_back(i);
    }
}

int main(){
  seive();
  return 0;
}
