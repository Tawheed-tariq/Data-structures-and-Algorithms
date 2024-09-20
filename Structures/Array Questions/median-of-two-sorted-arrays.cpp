#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> merge(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j=0;
        vector<int> ans;
        while(i < n && j < m){
            if(nums1[i] < nums2[j])
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        while(i < n){
            ans.push_back(nums1[i++]);
        }
        while(j < m){
            ans.push_back(nums2[j++]);
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res = merge(nums1, nums2);
        int n = res.size();
        if(n % 2 != 0){
            return double(res[n/2]);
        }
        else{
            double sum = res[n/2] + res[n/2 - 1];
            return double(sum/2);
        }
    }
};