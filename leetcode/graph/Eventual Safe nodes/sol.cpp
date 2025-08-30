class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, vector<int>& ans){
        visited[node] = true;
        pathVisited[node] = true;

        for(int i=0; i<graph[node].size(); i++){
            int neigh = graph[node][i];
            if(!pathVisited[neigh] && !visited[neigh]){
                if(!dfs(neigh, graph, visited, pathVisited, ans))
                    return false;
            }
            else if(pathVisited[neigh])    return false;
        }
        ans.push_back(node);

        pathVisited[node] = false;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<bool> visited(size, false);
        vector<bool> pathVisited(size, false);
        vector<int> ans;

        for(int i=0; i<size; i++){
            if(visited[i] == false){
                dfs(i, graph, visited, pathVisited, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

