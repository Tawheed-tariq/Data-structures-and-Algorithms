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
    bool isSimilar(string s1, string s2){
        int diff = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) diff++;

            if(diff > 2) return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                if(isSimilar(strs[i], strs[j])) ds.unionSets(i , j);
            }
        }

        int ans= 0;
        for(int i =0; i < n; i++){
            if(ds.findParent(i) == i) ans++;
        }
        return ans;
    }

};