class Solution {
public:
    bool detectCycle_util(int index, vector<vector<int>>& adjL, vector<int>& visited) {
        if (visited[index] == 1) {
            return true; // Cycle detected
        }
        if (visited[index] == 2) {
            return false; // Already processed, no cycle
        }
        visited[index] = 1; // Mark as under processing
        for (int neighbor : adjL[index]) {
            if (detectCycle_util(neighbor, adjL, visited)) {
                return true;
            }
        }
        visited[index] = 2; // Mark as processed
        return false;
    }
    bool detectCycle(vector<vector<int>>& adjL, int n){
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            if(!visited[i])
                if(detectCycle_util(i, adjL, visited)) return true;
        }
        return false;
    }
    void dfs(int index, vector<vector<int>> &adjL, vector<bool> & visited, stack<int> &res){
        if(visited[index]) return;

        visited[index] = true;
        for(auto &neighbor : adjL[index]){
            if(!visited[neighbor])
                dfs(neighbor, adjL, visited, res);
        }
        res.push(index);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        for(auto i : prerequisites){
            adjL[i[1]].push_back(i[0]);
        }

        if(detectCycle(adjL, numCourses)) return {};

        vector<bool> visited(numCourses, false);
        stack<int> res;

        for(int i = 0; i < numCourses; i++){
            if(!visited[i])
                dfs(i, adjL, visited, res);
        }
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            ans.push_back(res.top());
            res.pop();
        }
        return ans;
    }
};