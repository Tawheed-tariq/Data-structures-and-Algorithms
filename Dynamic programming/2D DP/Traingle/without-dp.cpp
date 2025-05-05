class Solution {
    public:
        int solve(int i, int j, vector<vector<int>>& triangle){
            if(i == triangle.size())
                return 0;
            
            int take_j = solve(i+1, j, triangle);
            int take_j_1 = solve(i+1, j+1, triangle);
    
            return triangle[i][j] + min(take_j, take_j_1);
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            return solve(0, 0, triangle);
        }
    };