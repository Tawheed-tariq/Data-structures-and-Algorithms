#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list
    unordered_map<int , list<pair<int,int>>> adj;
    for(int i = 0; i < m; i++){
        int u = g[i].first.first, v = g[i].first.second, w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> key(n+1);
    vector<int> parent(n+1);
    vector<bool> mst(n+1);
    for(int i = 0; i < n+1; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = 0;
    }
    //mark key of source as 0
    key[1] = 0;
    parent[1] = -1;
    for(int i = 1; i < n+1; i++){
        int min = INT_MAX, u;
        //find min node
        for(int j = 1; j < n+1; j++){
            if(mst[j] == 0 && key[j] < min ){
                min = key[j];
                u = j;
            }
        }
        //mark min node as true
        mst[u] = 1;
        //check adjacent
        for(auto it: adj[u]){
            int v = it.first, w = it.second;
            if(mst[v] == 0 && w < key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i <= n; i++){
        ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return ans;
}
