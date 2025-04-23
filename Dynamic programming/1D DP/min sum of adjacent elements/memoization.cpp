#include <bits/stdc++.h> 
int solve(vector<int> &nums, int ind, vector<int> &dp){
    if(ind >= nums.size())
        return 0;
    
    if(dp[ind] != -1)
        return dp[ind];
    int include = solve(nums, ind+2, dp) + nums[ind];
    int excude = solve(nums, ind+1, dp);

    return dp[ind] = max(include, excude);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size() + 1, -1);
    return solve(nums, 0, dp);
}