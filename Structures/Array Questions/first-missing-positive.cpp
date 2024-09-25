#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x:nums){
            mp[x] += 1;
        }
        for(int i =0;  i < nums.size(); i++){
            if(mp[i+1] == 0)
                return i+1;
        }
        return nums.size()+1;
    }
};