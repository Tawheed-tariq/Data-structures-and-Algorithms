#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create adj list
    unordered_map<int , list<pair<int, int>> > adj;
    for(int i = 0;  i < edges; i++){
        int u = vec[i][0], v = vec[i][1], w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> dist(vertices);
    for(int i = 0; i < vertices ;i++){
        dist[i]= INT_MAX;
    }
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDist = top.first, node = top.second;
        st.erase(st.begin());
        for(auto neighbour: adj[node]){
            if(nodeDist + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                //if record found then erase it
                if(record != st.end()){
                    st.erase(record);
                }
                dist[neighbour.first] = nodeDist + neighbour.second;
                //insert in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }     
        }
    }
    return dist;
}
