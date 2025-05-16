#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows >= 1)
            res.push_back({1});
        if(numRows >= 2)
            res.push_back({1,1});
        for(int i = 2; i < numRows; i++){
            vector<int> ans;
            vector<int> prev = res[i-1];
            ans.push_back(1);
            for(int j = 0; j+1 < prev.size(); j++){
                ans.push_back(prev[j]+prev[j+1]);
            }
            ans.push_back(1);
            res.push_back(ans);
        }
        return res;
    }
};