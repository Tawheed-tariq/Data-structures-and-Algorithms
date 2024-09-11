#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // approach 1
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i= 0; i < n; i++){
            mp[nums[i]] += 1;
        }
        for(auto x: mp){
            if(x.second > n/2)
                return x.first;
        }
        return -1;
    }
    // approach 2
    int majorityElement2(vector<int>& nums) {
        int count = 0, candidate = 0;
        for(auto x : nums){
            if(count == 0)
                candidate = x;
            if(x == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};