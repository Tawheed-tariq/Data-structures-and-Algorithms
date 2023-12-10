#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include "bits/stdc++.h"
bool isCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited,unordered_map<int, list<int> > &adj){
  visited[node] = 1;
  dfsVisited[node] = 1;
  for(auto neighbour: adj[node]){
    if(!visited[neighbour]){
      bool ans = isCycle(neighbour, visited, dfsVisited, adj);
      if(ans)
        return true;
    }else if(dfsVisited[neighbour]){
      //visited true
      return true;
    }
  }
  dfsVisited[node] = false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // create adjacecny list
  unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first, v = edges[i].second;
        adj[u].push_back(v);
  }
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;
    for(int i = 1; i < n; i++){
        if(!visited[i]){
            bool ans = isCycle(i , visited,dfsVisited, adj);
            if(ans)
                return true;
        }
    }
  return false;
}