class Solution {
    public:
        int LCS(string text1, string text2, int m, int n, vector<vector<int>> &table) {
            for(int i = 1; i <= m ; i++){
                for(int j = 1; j <= n; j++){
                    if(text1[i-1] == text2[j-1])
                        table[i][j] = 1 + table[i-1][j-1];
                    else
                        table[i][j] = max(table[i][j-1] , table[i-1][j]);
                }
            }
            return table[m][n];
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            int m = text1.size(), n = text2.size();
            vector<vector<int>> table(m+1, vector<int>(n+1, 0));
            return LCS(text1, text2, m, n, table);
        }
    };
    