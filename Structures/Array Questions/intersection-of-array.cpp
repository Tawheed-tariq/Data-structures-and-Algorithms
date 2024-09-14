#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> removeDuplicates(vector<int> &arr){
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            if(i == 0 || arr[i] != arr[i -1])
                ans.push_back(arr[i]);
        }
        return ans;
    }
    bool binarySearch(vector<int> &arr, int target){
        int s = 0, e = arr.size() -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] == target)
                return true;
            else if(arr[mid] < target)
                s = mid +1;
            else
                e = mid -1 ;
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        nums1 = removeDuplicates(nums1);
        nums2 = removeDuplicates(nums2);

        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;

        if(n1 > n2){
            for(int i = 0; i < n2; i++){
                if(binarySearch(nums1, nums2[i]))
                    ans.push_back(nums2[i]);
            }
        }
        else{
            for(int i = 0; i < n1; i++){
                if(binarySearch(nums2, nums1[i]))
                    ans.push_back(nums1[i]);
            }
        }
        return ans;
    }
};