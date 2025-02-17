#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeros;
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows*cols; i++){
            if(matrix[i/cols][i%cols] == 0)
                zeros.push_back({i/cols, i%cols});
        }

        for(auto x: zeros){
            for(int i = 0; i < cols; i++){
                matrix[x[0]][i] = 0;
            }
            for(int i = 0; i < rows; i++){
                matrix[i][x[1]] = 0;
            }
        }
    }
};