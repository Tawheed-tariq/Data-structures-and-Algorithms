class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int cols = matrix[0].size();
            int s = 0, e = matrix.size() * cols -1, mid;
    
            while(s <= e){
                mid = s + (e-s)/2;
                int row = mid/cols, col = mid % cols;
                if(matrix[row][col] == target)
                    return true;
                else if(matrix[row][col]  < target)
                    s = mid +1;
                else
                    e = mid -1;
            }
            return false;
        }
    };