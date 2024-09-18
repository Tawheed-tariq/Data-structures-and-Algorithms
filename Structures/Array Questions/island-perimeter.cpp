#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getPerimeter(vector<vector<int>>& grid, int i, int j){
        int rows = grid.size() - 1;
        int cols = grid[0].size() - 1;
        int p = 0;
        if(i == 0)
            p++;
        if(i == rows)
            p++;
        if(j == 0)
            p++;
        if(j == cols)
            p++;
        if(i < rows && grid[i+1][j] == 0)
            p++;
        if(i >0 && grid[i -1][j] == 0)
            p++;
        if(j >0 && grid[i][j-1] == 0)
            p++;
        if(j < cols && grid[i][j+1] == 0)
            p++;
        return p;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1)
                    ans += getPerimeter(grid, i ,j);
            }
        }
        return ans;
    }
};