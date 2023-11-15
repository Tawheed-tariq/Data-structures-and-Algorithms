#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int index, vector<int> &dp){
    if(index >= nums.size())
        return 0;
    if(index == nums.size()-1)
        return nums[nums.size() -1];
    //include
    if(dp[index] != -1)
        return dp[index];
    int inc = solve(nums, index+2, dp) + nums[index];
    //exclude
    int exc = solve(nums, index+1, dp) + 0;
    dp[index] = max(inc, exc);
    return dp[index];
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    int total = solve(nums, 0, dp);
    return total;
}