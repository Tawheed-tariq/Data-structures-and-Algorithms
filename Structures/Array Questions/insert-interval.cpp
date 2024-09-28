#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int start = newInterval[0], end = newInterval[1];
        vector<vector<int>> left, right;

        for(auto i:intervals){
            if(i[1]<start){
                left.push_back(i);
            }
            else if(i[0]>end){
                right.push_back(i);
            }
            else{
                start = min(start, i[0]);
                end = max(end, i[1]);
            }
        }

        vector<vector<int>> res;
        res.insert(res.end(), left.begin(), left.end());
        res.push_back({start, end});
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};