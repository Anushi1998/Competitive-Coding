/*
Implementation of trie with array for columar cache.

Since columnar unit is immutable, we can leverage this to remove Insert
property in trie, allowing to store trie in a compact array.

Corner case to be taken care of 
- Empty strings. (can be done easily, later?)
*/

#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;

int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}

#define ii pair<int,int>

// #define DEBUG

constexpr char ROOT = '*';

std::vector<std::string> input;

// Individual trie TrieNode.
struct TrieNode {
    TrieNode(char ch_, int children_, void* pg_str_): 
        ch(ch_), children(children_), pg_str(pg_str_) {};
        
    // Character
    char ch;
    // Exclusive index at which this TrieNode's children ends.
    int children;
    // Pointer to dictionary string. In this example, it points to input string.
    // Note: This will always be single pointer because dictionary comes
    // from sorted 'unique' values.
    void* pg_str;

    // HACK: Just for simplicity (to avoid implementing binary_search) using this.
    bool operator< (const TrieNode &rhs) const {
        return ch < rhs.ch;
    }
};

struct TrieEdge {
    TrieEdge() {};
    TrieEdge(char parent_, char child_, void* pg_str_): 
        parent(parent_), child(child_), pg_str(pg_str_) {};

    char parent;
    char child;
    void* pg_str;

    bool operator== (const TrieEdge &rhs) const {
        return (parent == rhs.parent) && (child == rhs.child);
    }

    bool operator!= (const TrieEdge &rhs) const {
        return !(*this == rhs);
    }
};

int trie_length = 0;
struct TrieNode *trie;

// input should be sorted before calling BuildTrie
void BuildTrie() {
    int max_length = 0, total_trie_size = 1; // Extra 1 for root
    for(auto& i: input) max_length = max(max_length, (int) i.size()), total_trie_size+= i.size();

    trie = (struct TrieNode *)malloc(total_trie_size * sizeof(struct TrieNode)); // MEMORY_COMPLEXITY

    trie[0] = TrieNode(ROOT, 1, nullptr);
    int prev_layer_ptr = 0;
    int cur_layer_ptr = 1;

    std::vector<TrieEdge> layer; // Can use array.
    for(int i=0;i<max_length;++i) {
        layer.clear();
        for(int j=0;j<input.size();++j) {
            if(input[j].size()<=i) continue;
            char parent = (i==0) ? ROOT : input[j][i-1];
            // Last character of this input string
            auto cur_edge = (input[j].size()-1 == i) ? 
                        TrieEdge(parent, input[j][i], &input[j]) 
                      : TrieEdge(parent, input[j][i], nullptr);
            if(j==0 || layer.back() != cur_edge) layer.push_back(cur_edge);
            if(cur_edge.pg_str) layer.back().pg_str = cur_edge.pg_str;
        } 

        int cur_layer_start = cur_layer_ptr;
        for(int j=0;j<layer.size();++j) {
            while(trie[prev_layer_ptr].ch != layer[j].parent) {
                trie[prev_layer_ptr++].children = cur_layer_ptr;
            }
            trie[cur_layer_ptr++] = TrieNode(layer[j].child, -1, layer[j].pg_str); 
        }
        trie[prev_layer_ptr].children = cur_layer_ptr;
        prev_layer_ptr = cur_layer_start;
    }
    trie_length = cur_layer_ptr;
}

void* SearchTrie(std::string who) {
    if(!trie_length) return nullptr;

    int where_in_trie=0;
    for(int i=0;i<who.length();i++) {
        int childrens_start = where_in_trie ? trie[where_in_trie-1].children : 1;
        int childrens_end = trie[where_in_trie].children;
        // We actually just need child comparision now, but for similicity using
        // TrieEdge struct.
        TrieNode* trie_node = std::lower_bound(trie + childrens_start, trie + childrens_end, TrieNode(who[i], 0, nullptr));

        if(trie_node->ch != who[i]) return nullptr; // No match
        where_in_trie =  trie_node - trie;
    }
    return trie[where_in_trie].pg_str; 
}

void DumpTrie() {
    cout<<"DumpTrie::Start"<<endl;
    for(int i=0;i<trie_length;++i) {
        cout<<"TrieNode#"<<i<<"::"<<trie[i].ch<<" "<<trie[i].children<<" "<<trie[i].pg_str<<endl;
    }
    cout<<"DumpTrie::End"<<endl;
}


int main(){
    int n,m;
    std::string a;
    
    # ifdef DEBUG 
    cout<<"Input strings:"<<endl;
    # endif
    cin>>n;
    for(int i=0;i<n;i++) { cin>>a; input.push_back(a); }

    sort(input.begin(), input.end());

    # ifdef DEBUG 
    cout<<"Building Trie..."<<endl;
    # endif
    BuildTrie();

    # ifdef DEBUG
    cout<<"Dumping Trie"<<endl;
    DumpTrie();
    # endif

    # ifdef DEBUG
    cout<<"Search strings?"<<endl;
    # endif
    cin>>m;
    while(m--) {
        cin>>a;
        void* search_result = SearchTrie(a);

        # ifdef DEBUG
        if(!search_result) cout<<"String not found! :("<<endl;
        else cout<<"String found::"<<*(reinterpret_cast<std::string*>(search_result))<<endl;
        # else
        if(!search_result) cout<<0<<endl;
        else cout<<1<<endl;
        #endif
    }
    return 0;
}

/*
# Sample Input
5               
abc
abcd
cad
cap
cat

4
abc
cap
xyz
adf

# Sample Output
Building Trie...
Dumping Trie

DumpTrie::Start
TrieNode#0::* 3 0
TrieNode#1::a 4 0
TrieNode#2::c 5 0
TrieNode#3::b 6 0
TrieNode#4::a 9 0
TrieNode#5::c 10 0
TrieNode#6::d -1 0x...
TrieNode#7::p -1 0x...
TrieNode#8::t -1 0x...
TrieNode#9::d -1 0x...
DumpTrie::End

Search strings?
String found::abc
String found::cap
String not found! :(
String not found! :(
*/
