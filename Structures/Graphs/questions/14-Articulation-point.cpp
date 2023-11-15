//docs -> https://www.codingninjas.com/studio/library/articulation-points-in-a-graph
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node , int parent, vector<int> &disc , vector<int> &low,
             unordered_map<int, bool> &visited, unordered_map<int , list<int> > &adj, vector<int> &ap, int &timer){
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto neigbour : adj[node]) { 
        if(neigbour == parent)
             continue;
        if (!visited[neigbour]){
            dfs(neigbour, node, disc, low, visited, adj, ap, timer);
            low[node] = min(low[node], low[neigbour]);
            //check articulation point
            if(low[neigbour] >= disc[node] && parent != -1)
                ap[node] = true;
            child++;
        } else {
            // backedge
            low[node] = min(low[node], disc[neigbour]);
        }
    }
    if(parent == -1 && child > 1){
        ap[node] = true;
    }
}
int main(){
    int n = 5, e = 5;
    vector<pair<int, int>> edges;
    unordered_map<int , list<int> > adj;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(1,2));

    for(int i =0 ; i < e; i++){
        int u = edges[i].first, v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0, parent = -1;
    vector<int> disc(n);
    vector<int> low(n);
    vector<int> ap(n,0);//articulation point
    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++){
        disc[i] = -1;
        low[i] = -1;
    }
    //dfs
    for(int i = 0;i< n; i++){
        if(!visited[i]){
            dfs(i , parent, disc, low, visited , adj ,ap,  timer);
        }
    }

    cout << "Articulation points are : " << endl;
    for(int i = 0; i < n; i++){
        if(ap[i] != 0){
            cout << i << "   ";
        }
    }
}