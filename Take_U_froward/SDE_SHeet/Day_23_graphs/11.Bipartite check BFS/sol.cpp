class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n, 0);
    
            for(int i = 0; i < n; i++){
                if(color[i] == 0){  //if not visited
                    queue<pair<int,int>> q;
                    q.push({i, 1});
                    color[i] = 1;
    
                    while(!q.empty()){
                        pair<int,int> front = q.front();
                        int node = front.first, c = front.second;
                        q.pop();
                        for(auto x: graph[node]){
                            if(color[x] == 0){
                                q.push({x, -c});
                                color[x] = -c;
                            }else if(color[x] == c){
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }
    };