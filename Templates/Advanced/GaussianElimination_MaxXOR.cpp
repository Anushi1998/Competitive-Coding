int bits(unsigned long long x){
    int ans=0;while(x) {x>>=1,ans++;}return ans;
}

unsigned long long who[65];
vector<unsigned long long> buckets[65];

unsigned long long Gauss(unsigned long long* a ,int n ,unsigned long long ans=0){
    memset(who,0,sizeof who);
    for(int i=0;i<n;i++)
        buckets[bits(a[i])].push_back(a[i]);
    for(int i=64;i;i--){
        if(buckets[i].empty()) continue;
        who[i]=buckets[i].back();buckets[i].pop_back();
        while(!buckets[i].empty()){
            buckets[bits(buckets[i].back()^who[i])].push_back(buckets[i].back()^who[i]);
            buckets[i].pop_back();
        }
    }
    buckets[0].clear();
    for(int i=64;i;i--)
        ans=max(ans,ans^who[i]);
    return ans;
}

Complexity : O(n)

Problem 1 : https://www.codechef.com/problems/XORSUB
Solution 1 : https://www.codechef.com/viewsolution/22515371
