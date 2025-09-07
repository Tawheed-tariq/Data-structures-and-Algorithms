// https://leetcode.com/problems/satisfiability-of-equality-equations/solutions/7165352/most-easy-to-understand-union-find-solution-time-o-n-amortized-and-space-o-1
class DisjointSet{
    vector<int> parent, rank;
public:
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSets(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pv] < rank[pu]) parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);

        for(auto &eqn : equations){
            if(eqn[1] == '='){
                int idx1 = eqn[0] - 'a';
                int idx2 = eqn[3] - 'a';
                ds.unionSets(idx1, idx2);
            }
        }

        for(auto &eqn : equations){
            if(eqn[1] == '!'){
                int idx1 = eqn[0] - 'a';
                int idx2 = eqn[3] - 'a';
                int p1 = ds.findParent(idx1);
                int p2 = ds.findParent(idx2);

                if(p1 == p2) return false;
            }
        }
        return true;
    }
};