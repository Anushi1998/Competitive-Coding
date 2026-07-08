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

bool solve(vector<int> v) {
    if(v.empty()) return false;
    int max = *max_element(v.begin(), v.end());
    if(max == 0) return true;
    int min = *min_element(v.begin(), v.end());
    if(min == 0) {
        vector<int> new_v;
        int cnt = 0;
        for(auto i : v) {
            if(i) {
                new_v.push_back(i);
            } else {
                cnt++;
            }
        }
        int res = solve(new_v);
        if(cnt>1) new_v.push_back(0);
        return !res || !solve(new_v);
    }
    for(int i = 1; i<= min; i++) {
        vector<int> new_v;
        for(auto j : v) {
            new_v.push_back(j-i);
        }
        int res = solve(new_v);
        if(!res) {
            return true;
        }
    }
    return false;
}

void test(vector<int>& v, int cnt) {
    if(cnt == 0) {
        cout<<v<<"::"<<(solve(v) ? "Win" : "Lose")<<endl;
        return;
    }
    vector<int> new_v = v;
    int low = v.empty() ? 0 : v.back();
    for(int i = low; i <= 10; i++) {
        new_v.push_back(i);
        test(new_v, cnt-1);
        new_v.pop_back();
    }
}

void win() {
    cout<<"Alice"<<endl;
}

void lose() {
    cout<<"Bob"<<endl;
}

void contest() {
    cin>>n;
    // vector<int> v2;
    // test(v2,n);
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    ranges::sort(v);
    if(v.size()==1) {
        if(v[0]==1) {
            return lose();
        }
        return win();
    }

    if(v[0]==0) {
        if(v.back()==0) {
            return win();
        }
        if(v.back() == (v.size()-1)) {
            return win();
        }
        int cnt=0;
        for(int i=1;i<v.size();i++) {
            if(v[i]<i) {
                return win();
            }
        }
        return lose();
    }
    if(v[0]==1) {
        int cnt=0;
        vector<int> new_v;
        for(int i=0;i<v.size();i++) {
            new_v.push_back(i+1);
        }
        if(v <= new_v) {
            return lose();
        }
        return win();
    }
    return win();

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