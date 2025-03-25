class Solution {
    public:
        int solve(string text1, string text2, int i, int j){
            if(i >= text1.size() || j >= text2.size()) return 0;
    
            if(text1[i] == text2[j]) return 1+solve(text1, text2, i+1, j+1);
    
            else return max(solve(text1, text2, i, j+1), solve(text1, text2, i+1, j));
    
        }
        int longestCommonSubsequence(string text1, string text2) {
            return solve(text1, text2, 0, 0);
        }
    };