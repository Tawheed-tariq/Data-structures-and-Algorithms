#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include "bits/stdc++.h"
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int , list<int> > &adj, stack<int> &st){
	visited[node] = 1;
	for(auto neighbour: adj[node]){
		if(!visited[neighbour]){
			dfs(neighbour, visited, adj, st);
		}
	}
	st.push(node);
}
void revDfs(int node, unordered_map<int, bool> &visited, unordered_map<int , list<int> > &adj){
	visited[node] = 1;
	for(auto neighbour: adj[node]){
		if(!visited[neighbour]){
			revDfs(neighbour, visited, adj);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// create adj list
	unordered_map<int , list<int> > adj;
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i][0], v = edges[i][1];
		adj[u].push_back(v);
	}

	//topological sort
	stack<int> st;
	unordered_map<int, bool> visited;
	for(int i = 0; i < v; i++){
		if(!visited[i]){
			dfs(i , visited ,adj , st);
		}
	}
	//create transpose
	unordered_map<int , list<int> > transpose;
	for(int i = 0; i < v; i++){
		visited[i] = 0;
		for(auto neighbour : adj[i]){
			transpose[neighbour].push_back(i);
		}
	}

	//dfs call using above ordering
	int count = 0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!visited[top]){
			count++;
			revDfs(top, visited , transpose);
		}
	}
	return count;
}