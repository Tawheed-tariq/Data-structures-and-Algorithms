class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int room = q.front();
            q.pop();
            vector<int> keys = rooms[room];

            for(int i = 0; i < keys.size(); i++){
                if(!visited[keys[i]]){
                    q.push(keys[i]);
                    visited[keys[i]] = true;
                }
            }
        }

        bool all = true;
        for(int i = 0; i < n; i++){
            if(!visited[i]) all = false;
        }
        return all;
    }
};