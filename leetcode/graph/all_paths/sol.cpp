class Solution {
public:
    void dfs(vector<vector<int>>& graph, int ind, vector<vector<int>>& paths, vector<int> &path){
        path.push_back(ind);
        if(ind == graph.size() - 1){
            paths.push_back(path);
            return;
        }

        for(auto &ele: graph[ind]){
            dfs(graph, ele, paths, path);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, 0, paths, path);
        return paths;
    }
};