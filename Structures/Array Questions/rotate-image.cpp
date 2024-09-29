#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void transpose(vector<vector<int>> &mat){
        int n = mat.size();
        for(int i = 0; i < n*n; i++){
            int row = i/n, col = i%n;
            if(col > row){
                swap(mat[row][col], mat[col][row]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int n = matrix.size();
        int i = 0, j = n-1;
        while(i < j){
            for(int k = 0; k < n; k++){
                swap(matrix[k][i], matrix[k][j]);
            }
            i++;
            j--;
        }
    }
};