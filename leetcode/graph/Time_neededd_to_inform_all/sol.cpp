class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;  // {employee, currentTime}
        q.push({headID, 0});
        int total = 0;

        while (!q.empty()) {
            auto [emp, time] = q.front();
            q.pop();
            total = max(total, time);  // track maximum time so far

            for (auto sub : graph[emp]) {
                q.push({sub, time + informTime[emp]});
            }
        }
        return total;
    }
};