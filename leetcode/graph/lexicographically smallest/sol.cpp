class DisjointSet{
    vector<int> parent;
public:
    DisjointSet(int n){
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

        if(pu < pv) parent[pv] = pu;
        else{
            parent[pu] = pv;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);

        for(int i = 0; i < s1.size(); i++){
            int idx1 = s1[i] - 'a';
            int idx2 = s2[i] - 'a';

            ds.unionSets(idx1, idx2);
        }
        string str;
        for(int i = 0; i < baseStr.size(); i++){
            int idx = baseStr[i] - 'a';
            int p = ds.findParent(idx);
            str.push_back(char(p + 'a'));
        }
        return str;
    }

};