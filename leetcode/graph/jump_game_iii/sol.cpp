class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), false);
        queue<int> q;
        int n = arr.size();

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int top = q.front(); q.pop();


            if(arr[top] == 0) return true;

            if(top + arr[top] < n && !visited[top + arr[top]]){
                q.push(top+ arr[top]);
                visited[top + arr[top]] = true;
            }

            if(top - arr[top] >= 0 && !visited[top - arr[top]]){
                q.push(top - arr[top]);
                visited[top - arr[top]] = true;
            }
        }
        return false;
    }
};