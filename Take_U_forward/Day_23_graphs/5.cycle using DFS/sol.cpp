class Solution {
    public:
        // 0-> Not visited
        // 1-> Under processing (part of DFS stack)
        // 2-> Fully processed (no cycle detected)
        bool dfs(int index, vector<vector<int>>& adjL, vector<int>& visited) {
            if (visited[index] == 1) {
                return true; // Cycle detected
            }
            if (visited[index] == 2) {
                return false; // Already processed, no cycle
            }
            visited[index] = 1; // Mark as under processing
            for (int neighbor : adjL[index]) {
                if (dfs(neighbor, adjL, visited)) {
                    return true;
                }
            }
            visited[index] = 2; // Mark as processed
            return false;
        }
        
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adjL(numCourses);
            for (vector<int> i : prerequisites) {
                adjL[i[1]].push_back(i[0]);
            }
            vector<int> visited(numCourses, 0);
            
            for (int i = 0; i < numCourses; i++) {
                if (dfs(i, adjL, visited)) {
                    return false; // Cycle found
                }
            }
            return true; // No cycle detected
        }
    };