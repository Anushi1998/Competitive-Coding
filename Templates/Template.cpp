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

#ifdef LOCAL
#define dout cerr
#else
struct NullStream {
    template <typename T>
    NullStream& operator<<(const T&) { return *this; }
    NullStream& operator<<(ostream& (*)(ostream&)) { return *this; }
} dout;
#endif

int n,k;
int a[N],b[N];
string s;

void contest() {
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        dout<<"=========================";
        contest();
    }
    return 0;
}