#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                arr.push_back(i);
        }
        for(int i = 0; i < arr.size(); i++){
            nums[i] = nums[arr[i]];
        }
        for(int i = arr.size(); i < n; i++){
            nums[i] = 0;
        }
    }
};