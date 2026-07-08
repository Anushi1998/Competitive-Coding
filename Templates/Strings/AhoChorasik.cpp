#include<bits/stdc++.h>
using namespace std;

const int N=500010;
const int mod=1e9+7;
const int atcoderMod=998244353;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define ii pair<int,int>

template<typename T>
concept HasOStream = requires(std::ostream& os, T v) {
    os<<v;
};

template<typename T>
concept IsTupleLike = requires {
    typename std::tuple_size<T>::type;
};

template<IsTupleLike T>
requires (!HasOStream<T>) 
std::ostream& operator<<(std::ostream& os, const T& t) {
    os << "{";
    std::apply([&os](const auto&... args) {
        size_t n = 0;
        ((os << args << (++n != sizeof...(args) ? "," : "")), ...);
    }, t);
    return os << "}";
}

template<std::ranges::range T>
requires (!HasOStream<T>)
ostream& operator<<(ostream& os, const T& v) {
    os<<"[";
    for(auto it = v.begin(); it != v.end(); it++) {
        os<<*it<<(next(it) != v.end() ? ", " : "");
        
    }
    os<<"]";
    return os;
}

int n,k;
int a[N],b[N];
string s;

template<typename T>
concept Equatable = requires(T a, T b) {
    {a == b} -> convertible_to<bool>;
    {a != b} -> convertible_to<bool>;
};

template<typename T, typename Index>
requires(Equatable<T>)
struct Node {
    Node(T val): val(val) {}

    T val;
    weak_ptr<Node> suffixLink;
    map<T, shared_ptr<Node>> children;
    optional<Index> patternIndex;
};

template<typename T>
class AhoCorasick {
    using ACNode = Node<T>;

    AhoCorasick(): root(ACNode(T{})) {
        root->suffixLink = root;
    }

    // This is wrong, patterns can't be dynamically added, and also need to be sorted
    // Should be used with caution.
    void addPattern(vector<T> pattern, Index index) {
        auto where = root;
        for(auto pc: pattern) {
            auto& children = where->children;
            auto it = children.find(pc);
            if(it == children.end()) {
                children[pc] = shared_ptr(ACNode(pc));
                auto& node = children[pc];
                node->suffixLink = computeSuffixLink(where);
                it = children.find(pc);
            }
            where = it;
        }
        // Assuming unique patterns
        where.patternIndex = optional(index);
    }

    void addPatterns(vector<vector<T>> patterns, vector<Index> indexes) {
        auto bfsCmp = [&](int i, int j) {
            if(patterns[i].size() != patterns[j].size()) {
                return patterns[i].size() < patterns[j].size();
            }
            return patterns[i] < patterns[j];
        };
        ranges::sort(indexes, bfsCmp);
        ranges::sort(patterns, bfsCmp);
        views::zip(patterns, indexes) | views::transfor([](auto pattern, auto index) {
            addPattern(pattern, index);
        });
    }

    void search(vector<T> target) {
        
    }

private:
    shared_ptr<ACNode> root;

    weak_ptr<ACNode> computeSuffixLink(shared_ptr<ACNode> where, T elem) {
        auto cur = where->suffixLink;
        while(true) {
            if(cur->children.find(elem) != cur->children.end()) {
                return cur->children[elem];
            }
            if(cur->suffixLink == cur) return cur;
            cur = cur->suffixLink;
        }
    } 
};

void contest() {
    auto timeStamp = chrono::steady_clock::now();
    auto v = static_cast<chrono::milliseconds>(timeStamp.time_since_epoch()).count();
    // decltype(v) v2 = 1ms;
    cout<<v<<endl;
    // this_thread::sleep_for(chrono::milliseconds(1000));
    // auto timeStamp2 = chrono::steady_clock::now();
    // cout<<static_cast<chrono::milliseconds>(timeStamp2.time_since_epoch()).count()<<endl;
    // cout<<static_cast<chrono::milliseconds>(timeStamp2 - timeStamp).count()<<endl;

    
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        cout<<"=========================";
        contest();
    }
    return 0;
}