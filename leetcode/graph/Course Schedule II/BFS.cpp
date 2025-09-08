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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto i : prerequisites){
            adjL[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        if(detectCycle(adjL, numCourses)) return {};

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;

        while(!q.empty()){
            int top = q.front(); q.pop();
            ans.push_back(top);
            for(auto &ele: adjL[top]){
                indegree[ele]--;
                if(indegree[ele] == 0){
                    q.push(ele);
                }
            }
        }
        return ans;
    }
};