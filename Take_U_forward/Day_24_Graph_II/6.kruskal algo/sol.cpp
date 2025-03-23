class UnionFind{
    vector<int> parent, rank;
    public:
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n, 0); //for every element initial rank is 0
            for(int i = 0; i < n; i++) parent[i] = i; //initially parent of node is node itself
        }
        
        int find(int x){
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        bool unionSets(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            
            if(rootX == rootY) return false; //cycle formed
            
            if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            }else if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            }else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
};

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        UnionFind uf(V);
        
        for(int u = 0; u < V; u++){
            for(auto neighbor : adj[u]) {
                int v = neighbor[0];
                int wt = neighbor[1];
                
                if(u < v) { // To avoid duplicate edges in undirected graph
                    pq.push({wt, {u, v}});
                }
            }
        }
        
        int sum = 0;
        int i = 0;
        while(i < V-1 && !pq.empty()){
            auto edge = pq.top();
            pq.pop();
            int x = edge.second.first;
            int y = edge.second.second;
            if(uf.unionSets(x, y)){
                sum += edge.first;
                i++;
            }
        }
        return sum;
    }
};