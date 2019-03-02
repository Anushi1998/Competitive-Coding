#include <bits/stdc++.h>
using namespace std;
#define N 100111
#define ll long long

typedef pair<ll,ll> pt;
#define x first
#define y second

pt add(pt a, pt b) {
    return make_pair(a.x + b.x, a.y + b.y);
}
ll cross(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

bool crosscomp(pt a, pt b) {
    return cross(a, b) > 0;
}
ll xs[N];
ll ys[N];
int n;

vector<pt> pts;
pt zero = make_pair(0LL, 0LL);
struct tree {
    pt a, b;
    pt total;
    tree *l, *r;
    tree(pt a, pt b, pt total, tree *l, tree *r): a(a), b(b), total(total), l(l), r(r) {}

    tree *insert(pt v) {
        if ((v.x || v.y) && cross(a, v) >= 0 && cross(v, b) >= 0) {
            if (l) {
                tree *nl = l->insert(v);
                tree *nr = r->insert(v);
                return new tree(a, b, add(nl->total, nr->total), nl, nr);
            } else {
                return new tree(a, b, add(total, v), l, r);
            }
        } else {
            return this;
        }
    }

    pt query(pt v) {
        if (cross(a, v) < 0) {
            return zero;
        } else if (cross(b, v) >= 0) {
            return total;
        } else {
            return add(l->query(v), r->query(v));
        }
    }

    void print(int indent = 0) {
        for (int i = 0; i < indent; i++) printf("  ");
        printf("(%lld %lld) (%lld %lld): total=(%lld %lld)\n", a.x, a.y, b.x, b.y, total.x, total.y);
        if (l) {
            l->print(indent+1);
            r->print(indent+1);
        }
    }
};

tree *make_tree(int i, int j) {
    tree *l, *r;
    if (i == j) {
        l = r = NULL;
    } else {
        int k = i + j >> 1;
        l = make_tree(i, k);
        r = make_tree(k+1, j);
    }
    return new tree(pts[i], pts[j], zero, l, r);
}

tree *trees[N];
void init() {
    vector<pt> opts;
    for (int i = 0; i < n; i++) {
        if (xs[i] || ys[i]) opts.push_back(make_pair(xs[i], ys[i]));
    }
    sort(opts.begin(), opts.end(), crosscomp);
    for (int i = 0; i < opts.size(); i++) {
        if (!i || cross(opts[i], opts[i-1]) != 0) pts.push_back(opts[i]);
    }
    trees[0] = make_tree(0, pts.size()-1);
    for (int i = 0; i < n; i++) {
        trees[i+1] = trees[i]->insert(make_pair(xs[i], ys[i]));
    }
    // // print trees
    // for (int i = 0; i <= n; i++) {
    //     trees[i]->print();
    // }
}

ll _query(int i, pt v) {
    return cross(trees[i]->query(v), v);
}

ll query(int l, int r, ll x, ll y) {
    pt v = make_pair(x, y);
    return _query(r, v) - _query(l, v);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &xs[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &ys[i]);
    init();
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        ll x, y;
        scanf("%d%d%lld%lld", &l, &r, &y, &x);
        printf("%lld\n", x == 0 && y == 0 ? 0LL : query(--l, r, x, y));
        fflush(stdout);
    }
}
