class Solution {
public:
    int solve(vector<vector<int>>& pairs, int n, int curr, int prev, vector<vector<int>> &dp){
        if(curr == n) return 0;

        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        int not_take = solve(pairs, n, curr+1, prev, dp);

        int take = 0;
        if(prev == -1 || pairs[prev][1] < pairs[curr][0])
            take = 1 + solve(pairs, n, curr+1, curr, dp);
        return dp[curr][prev+1] = max(not_take, take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(pairs.size()+1, vector<int>(pairs.size()+1 , -1));
        return solve(pairs, pairs.size(), 0, -1, dp);
    }
};