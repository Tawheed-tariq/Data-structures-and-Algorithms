#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj, vector<int> &comp){
    comp.push_back(node);
    visited[node] = 1;
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i, visited, adj, comp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> comp;
            dfs(i , visited , adj, comp);
            ans.push_back(comp);
        }
    }

    return ans;
}