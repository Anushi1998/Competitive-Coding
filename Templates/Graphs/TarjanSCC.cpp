int dfsNum[N],dfsMin[N];
vector<vector<int> >SCC;
bitset<N> v;
vector<int> cur;
int counter;

void tarjanSCC(int id,int p){
  dfsMin[id]=dfsNum[id]=counter++;
  v[id]=1;
  cur.push_back(id);

  for(auto &i:adj[id]){
    if(!v[i]) tarjanSCC(i);
    dfsMin[id]=min(dfsMin[id],dfsMin[i]);
  }

  if(dfsMin[id]==dfsNum[id]){
    SCC.push_back(vector<int>);
    while(true) {
      int who=cur.back();cur.pop_back();v[who]=0;
      SCC.back().push_back(who);
      if(who==id) break;
    }
  }
}


for(int i=0;i<n;i++) if(!v[i]) tarjanSCC(i);

struct Edge {
    int from;
    int to;
    int weight;
};

enum class EdgeType {
    UNDIRECTED_UNWEIGHTED,
    DIRECTED_UNWEIGHTED,
    DIRECTED_WEIGHTED,
    UNDIRECTED_WEIGHTED,
};

class Graph {
public:
    int n;
    vector<vector<Edge>> g;
    
    Graph(int n) : n(n) { g.resize(n); }
    Graph(int n, vector<vector<Edge>> edges) : n(n), g(edges) { }
    
    void inputEdges(int m, EdgeType type = EdgeType::UNDIRECTED_UNWEIGHTED) {
        int u,v,w=1;
        for(int i=1;i<=m;i++) {
            switch(type) {
                case EdgeType::UNDIRECTED_UNWEIGHTED:
                case EdgeType::DIRECTED_UNWEIGHTED:
                    cin>>u>>v;
                    break;
                case EdgeType::DIRECTED_WEIGHTED:
                case EdgeType::UNDIRECTED_WEIGHTED:
                    cin>>u>>v>>w;
                    break;
            }
            --u,--v;
            g[u].emplace_back(u,v,w);
            if(type == EdgeType::UNDIRECTED_UNWEIGHTED || type == EdgeType::UNDIRECTED_WEIGHTED) {
                g[v].emplace_back(v,u,w);
            }
        }
    }

    vector<int> topologicalDfs(int start) {
        vector<bool> v(n,false);
        vector<int> ans;
        dfs(start,v,ans);
        for(int i=0;i<n;i++) {
            if(!v[i]) dfs(i,v,ans);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void dfs(int id, vector<bool>& v, vector<int>& ans) {
        v[id] = true;
        for(auto [from,to,w] : g[id]) {
            if(!v[to]) dfs(to,v,ans);
        }
        ans.push_back(id);
    }

    Graph transpose() {
        vector<vector<Edge>> transposed(n);
        for(int node=0;node<n;node++) {
            for(auto [from,to,w] : g[node]) {
                transposed[to].push_back({to,from,w});
            }
        }
        return Graph{n,transposed};
    }

    vector<vector<int>> scc() {
        if(n==0) return {{}};
        vector<int> topologicalOrder = topologicalDfs(0);
        Graph transposedGraph = transpose();
        vector<vector<int>> scc;
        vector<bool> transposedVisited(n,false);
        for(int id : topologicalOrder) {
            if(transposedVisited[id]) continue;
            vector<int> component;
            transposedGraph.dfs(id,transposedVisited,component);
            scc.emplace_back(std::move(component));
        }
        return scc;
    }
};