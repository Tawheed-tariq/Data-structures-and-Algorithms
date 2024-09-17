#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int , int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            mp[i+1] = 0;
        }
        for(auto num : nums){
            mp[num] += 1;
        }
        for(auto x : mp){
            if(x.second == 0)
                ans.push_back(x.first);
        }
        return ans;
    }
};