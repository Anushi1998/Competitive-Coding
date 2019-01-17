int BIT[N];

int query(int pos,int ans=0){
	for(;pos;pos-=pos&(-pos)) ans+=BIT[pos];return ans;
}

void update(int pos,int val=1){
	for(;pos<=n;pos+=pos&(-pos)) BIT[pos]+=val;
}

Problem 1: https://codeforces.com/contest/501/submission/48443789
