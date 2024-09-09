#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind1 = 0, ind2 = 0;
        vector<int> ans;
        while(ind1 < m && ind2 < n){
            if(nums1[ind1] < nums2[ind2]){
                ans.push_back(nums1[ind1++]);
            }
            else{
                ans.push_back(nums2[ind2++]);
            }
        }
        while(ind1 < m){
            ans.push_back(nums1[ind1++]);
        }
        while(ind2 < n){
            ans.push_back(nums2[ind2++]);
        }
        for(int i =0; i < m+n; i++){
            nums1[i] = ans[i];
        }
    }
};