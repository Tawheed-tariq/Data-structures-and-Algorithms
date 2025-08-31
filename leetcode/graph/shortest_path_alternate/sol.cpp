class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {        //1 --> red, 2--> blue
        vector<int> ans(n , -1);
        vector<vector<pair<int, int>>> graph(n);
        queue<pair<int, int>> q;

        q.push({0, -1});

        for(const auto &edge : redEdges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({v, 1});
        }

        for(const auto &edge : blueEdges){
            int u = edge[0], v = edge[1];
            graph[u].push_back({v, 2});
        }

        int step = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                const auto [u, prevColor] = q.front();
                q.pop();

                ans[u] = ans[u] == -1? step : ans[u];

                for(auto &[v, edgeColor]: graph[u]){
                    if(v == -1 || edgeColor == prevColor ) continue;
                    q.push({v, edgeColor});
                    v = -1; //set as used
                }
            }
            step++;
        }

        return ans;
    }
};