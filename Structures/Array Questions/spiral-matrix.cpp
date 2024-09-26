#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int s_row =0, s_col = 0, e_row = matrix.size()-1, e_col = matrix[0].size() -1;
        int count = 0, total = (e_row+1)*(e_col+1);
        while(count < total){
            for(int i = s_col; i <= e_col && count < total; i++){
                ans.push_back(matrix[s_row][i]);
                count++;
            }
            s_row++;
            for(int i = s_row; i <= e_row && count < total ; i++){
                ans.push_back(matrix[i][e_col]);
                count++;
            }
            e_col--;
            for(int i =e_col; i >= s_col && count < total; i--){
                ans.push_back(matrix[e_row][i]);
                count++;
            }
            e_row--;
            for(int i = e_row; i >= s_row && count < total; i--){
                ans.push_back(matrix[i][s_col]);
                count++;
            }
            s_col++;
        }
        return ans;
    }
};