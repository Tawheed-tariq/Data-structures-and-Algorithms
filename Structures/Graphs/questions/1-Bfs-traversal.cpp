#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> ans;
    unordered_map<int , bool > visited;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto i : adj[front]) {
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}