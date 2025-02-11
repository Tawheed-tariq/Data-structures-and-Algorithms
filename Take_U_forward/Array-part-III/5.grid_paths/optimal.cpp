class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> path(m, vector<int>(n, -1));
            return find(path, m-1, n-1);
        }
        int find(vector<vector<int>> &path, int m, int n){
            if(m == 0 || n == 0)
                return 1;
            
            if(path[m][n] != -1)
                return path[m][n];
    
            path[m][n] = find(path, m-1, n) + find(path, m, n-1);
    
            return path[m][n];
        }
    };