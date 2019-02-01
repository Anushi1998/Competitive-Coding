#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
const int mod = 1e9 + 7;

//https://github.com/Anushi1998/Competitive-Coding/blob/master/Data-Structures/SegmentTree.cpp
template <class T>
class SegmentTree {
public:
    vector<T> st;
    int n;
    T(*f)(T, T);
    SegmentTree(T(*who)(T, T)){
        f = who;
    }
    void build(int sz, T *a, T(*cur)(T, T*)){
        n = sz;
        st.resize(n + n + 1);
        for (int i = 0; i<n; i++) st[n + i] = (*cur)(i, a);
        for (int i = n - 1; i>0; i--) st[i] = (*f)(st[i << 1], st[i << 1 | 1]);
    }
    void modify(int id, T val){
        for (st[id += n] = val; id>1; id >>= 1) st[id >> 1] = (*f)(st[id], st[id ^ 1]);
    }
    T query(int l, int r, T res){
        ++r;
        for (l += n, r += n; l<r; l >>= 1, r >>= 1){
            if (l & 1) res = (*f)(res, st[l++]);
            if (r & 1) res = (*f)(res, st[--r]);
        }
        return res;
    }
    void print(){
        for (int i = 1; i<n + n; i++) cout << st[i] << ' '; cout << endl;
    }
};

int min_(int a, int b){ return (a<b) ? a : b; }
int max_(int x, int y){ if (y>x) swap(x, y); return (a[x]>a[y]) ? x : y; }
int add(int x, int y){ return (x + 0LL + y) % mod; }
int value(int id, int* a){ return a[id]; }
int index(int id, int* a){ return id; }

SegmentTree<int> mi(min_);

int n, a[N];

int main(){
	cin >> n;
	for (int i = 0; i<n; i++) cin >> a[i];
	mi.build(n, a, value);
	cout<<mi.query(0,n-1,mod)<<endl;
	mi.modify(0,-1000);
	cout<<mi.query(0,n-1,mod)<<endl;
	mi.print();
	return 0;
}

Problem 1 : https://www.codechef.com/viewsolution/19595751
