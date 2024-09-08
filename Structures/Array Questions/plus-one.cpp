#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() -1;
        int sum = digits[n] +1;
        for(int i = n; i >=0 ;i--){
            if(sum != 10){
                digits[i] = sum;
                break;
            }
            else{
                digits[i] = 0;
                if(i !=0){
                    sum = digits[i-1] +1;
                }
                else{
                    digits[i] = 0;
                    digits.push_back(1);
                    rotate(digits.rbegin(), digits.rbegin() + 1, digits.rend());
                }
            }
        }
        return digits;
    }
};