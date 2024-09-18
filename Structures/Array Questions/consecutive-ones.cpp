#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                ones++;
            else{
                ans = max(ones, ans);
                ones = 0;
            }
        }
        ans = max(ones, ans);
        return ans;
    }
};