#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &ans, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis) {
  vis[node] = true;
  disc[node] = low[node] = timer++;
  for (auto neigbour : adj[node]) { 
    if (neigbour == parent)
      continue;
    if (!vis[neigbour]) {
      dfs(neigbour, node, timer, disc, low, ans, adj, vis);
      low[node] = min(low[node], low[neigbour]);
      //check for bridge edge
      if(low[neigbour]>disc[node]){
          vector<int>res;
          res.push_back(node);
          res.push_back(neigbour);
          ans.push_back(res);
      }
    } else {
      // backedge
      low[node] = min(low[node], disc[neigbour]);
    }
  }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
  // craete adj list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // cretae data structures
  int timer = 0;
  vector<int> disc(v);
  vector<int> low(v);
  int parent = -1;
  unordered_map<int, bool> vis;
  for (int i = 0; i < v; i++) {
    disc[i] = -1;
    low[i] = -1;
  }
  vector<vector<int>> ans;
  // dfs
  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      dfs(i, parent, timer, disc, low, ans, adj, vis);
    }
  }
  return ans;
}