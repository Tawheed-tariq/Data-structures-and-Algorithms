#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(auto x: nums){
            mp[x] +=1;
            if(mp[x] >1)
                return true;
        }
        return false;
    }
};