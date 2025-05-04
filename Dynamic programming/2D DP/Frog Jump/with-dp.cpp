class Solution {
    public:
        unordered_map<int, int> mp;
        int dp[2000][2000];
    
        int solve(int ind, int jump, vector<int>& stones){
            if(ind == stones.size() - 1) return true;
    
            if(dp[ind][jump] != -1) return dp[ind][jump];
    
            bool k0 = false;
            bool k = false;
            bool k1 = false;
    
            if(mp.find(stones[ind] + jump) != mp.end()){
                k = solve(mp[stones[ind] + jump], jump, stones);
            }
    
            if(jump > 1 && mp.find(stones[ind] + jump-1) != mp.end()){
                k0 = solve(mp[stones[ind] + jump-1], jump-1, stones);
            }
    
            if(mp.find(stones[ind] + jump + 1) != mp.end()){
                k1 = solve(mp[stones[ind] + jump + 1], jump+ 1, stones);
            }
    
            dp[ind][jump] = k0 || k || k1;
            return dp[ind][jump];
        }
    
        bool canCross(vector<int>& stones) {
            if(stones[1] - stones[0] != 1) return false;
            for(int i = 0; i < stones.size(); i++){
                mp[stones[i]] = i;
            }
    
            memset(dp, -1, sizeof(dp));
    
            return solve(1, 1, stones);
        }
    };