// If we XOR something with 0, it will return the same number
//     example: 5^0 = 5

// If we XOR 2 same numbers the output wil be 0
//     example: 5^5 = 0

// if we XOR 2 different numbers it will result nothing
//     example 4^5 = 4^5

// Here, we will XOR each number present in the nums to itself
// 0^1^2^3^.....^n
// Then will XOR it with every number present in range [0,n]
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i =1; i<= nums.size(); i++){
            ans ^= i;
        }
        for(int i =0; i< nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};