class Solution {
public:
    int solve(vector<int> &arr, int difference, int curr, int prev, vector<vector<int>> &dp){
        if(curr == arr.size()) return 0;

        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        int not_take = solve(arr, difference, curr+1, prev, dp);

        int take = 0;
        if(prev == -1 || arr[curr] - arr[prev] == difference)
            take = 1 + solve(arr, difference, curr+1, curr, dp);

        return max(take, not_take);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<vector<int>> dp(arr.size() + 1, vector<int> (arr.size() + 1, -1));
        return solve(arr, difference, 0, -1, dp);
    }
};