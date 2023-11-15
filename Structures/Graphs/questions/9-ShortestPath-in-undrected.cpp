#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// create adj list
	unordered_map<int,list<int> > adj;
	for(int i = 0; i< edges.size(); i++){
		int u = edges[i].first, v = edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	unordered_map<int,bool> visited;
	unordered_map<int , int> parent;
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	parent[s] = -1;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(auto i: adj[front]){
			if(!visited[i]){
				parent[i] = front;
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	//prepare shotest path
	vector<int> ans;
	int curr = t;
	ans.push_back(t);
	while(curr != s){
		curr = parent[curr];
		ans.push_back(curr);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
