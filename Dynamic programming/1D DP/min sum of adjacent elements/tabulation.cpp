#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums){
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for(int i = 1; i< nums.size(); i++){
        int inc = nums[i] + dp[i-2];
        int exc = dp[i-1] + 0;
        dp[i] = max(inc, exc); 
    }
   return dp[nums.size() - 1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int total = solve(nums);
    return total;
}