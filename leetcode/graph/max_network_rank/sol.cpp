class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> mp;

        for(auto &road: roads){
            mp[road[0]].insert(road[1]);
            mp[road[1]].insert(road[0]);
        }
        int ans = 0;
        for(int i = 0; i < n;i++){
            for(int j = i+1; j < n; j++){
                int total = mp[i].size() + mp[j].size();
                if(mp[i].find(j) != mp[i].end()) total--;
                ans = max(ans, total);
            }
        }

        return ans;
    }
};