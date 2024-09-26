#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size(), maxInd = nums[0];
        for(int i = 0; i < n; i++){
            if(maxInd >= n-1)
                return true;
            if(nums[i] == 0 && maxInd == i)
                return false;
            if(i + nums[i] > maxInd)
                maxInd = i + nums[i];
        }
        return true;
    }
};