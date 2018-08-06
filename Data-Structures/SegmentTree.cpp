#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
const int mod = 1e9 + 7;

int fun(int a, int b){
	return min(a, b);
}

template <class T>
class SegmentTree {
public:
	vector<T> st;
	int n;
	T(*f)(T, T);
	SegmentTree(T(*who)(T, T)){
		f = who;
	}
	void build(int sz, T *a){
		n = sz;
		st.resize(n + n + 1);
		for (int i = 0; i<n; i++) st[n + i] = a[i];
		for (int i = n - 1; i>0; i--) st[i] = (*f)(st[i << 1], st[i << 1 | 1]);
	}
	void build(vector<T> a){
		n = a.size();
		st.resize(n + n);
		for (int i = 0; i<n; i++) st[n + i] = a[i];
		for (int i = n - 1; i>0; i--) st[i] = (*f)(st[i << 1], st[i << 1 | 1]);
	}
	void modify(int id, T val){
		for (st[id += n] = val; id>1; id >>= 1) st[id >> 1] = (*f)(st[id], st[id ^ 1]);
	}
	T query(int l, int r, T res){
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=(*f)(res,st[l++]);
			if(r&1) res=(*f)(res,st[--r]);
		}
		return res;
	}
	void print(){
		for (int i = 1; i<n+n; i++) cout << st[i] << ' '; cout << endl;
	}
};

int n, a[N];

int main(){
	cin >> n;
	for (int i = 0; i<n; i++) cin >> a[i];
	SegmentTree<int> x(fun);
	x.build(n, a);
	x.print();
	return 0;
}
