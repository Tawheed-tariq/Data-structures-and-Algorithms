#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums){
    int prev = 0;
    int prev1 = nums[0];
    for(int i = 1; i< nums.size(); i++){
        int inc = nums[i] + prev;
        int exc = prev1 + 0;
        int curr = max(inc, exc);
        prev = prev1;
        prev1 = curr;
    }
   return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int total = solve(nums);
    return total;
}