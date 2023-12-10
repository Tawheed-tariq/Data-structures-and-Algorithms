#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u , int v, bool direction){
        //direction -> 0 => undirected
        //direction -> 1 => directed


        //create edge from u to v
        adj[u].push_back(v);
        if(direction == 0)
            adj[v].push_back(u);
    }
    void printEdges(){
        for(auto i:adj){
            cout << i.first << "->  ";
            for(auto j: i.second){
                cout << j<< ",  ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n, m;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    graph gh;
    cout << "Enter edges" << endl;
    for(int i = 0; i < m; i++){
        int u , v;
        cin >> u >> v;
        gh.addEdge(u,v,0);
    }
    gh.printEdges();
}