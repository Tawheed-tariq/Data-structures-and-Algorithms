// https://leetcode.com/problems/evaluate-division/solutions/7058960/easy-solution-100-beats-solve-like-a-pro-java-python-c
class Solution {
public:
    double dfs(string curr, string target, unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited){
        if(graph.find(curr) == graph.end() || graph.find(target) == graph.end()) return -1.0;
        if(curr == target) return 1.0;

        visited.insert(curr);

        for(auto & neighbor : graph[curr]){
            string next = neighbor.first;
            double weight = neighbor.second;

            if(!visited.count(next)){
                double res = dfs(next, target, graph, visited);
                if(res != -1.0) return weight * res;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        //build graph
        for(int i = 0; i < equations.size(); i++){
            string u = equations[i][0], v = equations[i][1];
            double val = values[i];
            graph[u][v] = val;
            graph[v][u] = 1/val;
        }

        //process queries
        vector<double> results;
        for(int i = 0; i < queries.size(); i++){
            string strt = queries[i][0], end = queries[i][1];
            unordered_set<string> visited;
            double ans = dfs(strt, end, graph, visited);
            results.push_back(ans);
        }

        return results;
    }
};