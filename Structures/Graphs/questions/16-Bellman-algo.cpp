#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1, (int) 1e8); //at starting every node contains bigger number
    dist[src] = 0;
    //run loop n-1 times
    for(int i = 1; i < n; i++){
        //traverse edge list
        for(int j = 0 ; j < m; j++){
            int u = edges[j][0], v = edges[j][1], w= edges[j][2];
            if( (dist[u] + w) < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    //check for cycle
    bool cycle = 0;
    for(int j = 0 ; j < m; j++){
        int u = edges[j][0], v = edges[j][1], w= edges[j][2];
        if( (dist[u] + w) < dist[v]){
            cycle = 1;
            break;
        }
    }
    if(!cycle)
        return dist;
}