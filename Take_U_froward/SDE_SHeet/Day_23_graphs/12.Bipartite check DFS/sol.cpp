class Solution {
    public:
        bool dfs(int node, int color_i, vector<int> &color, vector<vector<int>>& graph){
            color[node] = color_i;
            for(auto x: graph[node]){
                if(color[x] == 0 && !dfs(x, -color_i, color, graph)) return false;
                else if (color[x] == color_i)
                    return false;
            }
            return true;
        }
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n, 0);
    
            for(int i = 0; i < n; i++){
                if(color[i] == 0){  //if not visited
                    if(!dfs(i, 1, color, graph)) return false;
                }
            }
            return true;
        }
    };