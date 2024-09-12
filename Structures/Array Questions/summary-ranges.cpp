#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        int count= nums[0], prevInd = 0;
        for(int i = 0; i < nums.size(); i++){
            string s = to_string(nums[prevInd]);
            if(nums[i] != count){
                if(nums[prevInd] != nums[i-1])
                    s += "->" + to_string(nums[i-1]);
                ans.push_back(s);
                prevInd = i;
                count = nums[i];
                i--;
            }
            else if(i == nums.size() -1){
                if(nums[prevInd] != nums[i])
                    s += "->" + to_string(nums[i]);
                ans.push_back(s);
            }
            else
                count++;
        }
        return ans;
    }
};