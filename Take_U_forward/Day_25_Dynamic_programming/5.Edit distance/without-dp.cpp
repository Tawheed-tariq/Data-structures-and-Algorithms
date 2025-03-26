class Solution {
    public:
        int solve(int i, int j, string word1, string word2){
            if(j == 0) return i;
            if(i == 0) return j;
    
            if(word1[i-1] == word2[j-1]) return solve(i-1, j-1, word1, word2);
    
            int ans = INT_MAX;
            ans = min(ans, 1+solve(i-1, j-1, word1, word2));
            ans = min (ans, 1+solve(i, j-1, word1, word2));
            ans = min(ans, 1+solve(i-1, j, word1, word2));
    
            return ans;
        }
        int minDistance(string word1, string word2) {
            int n1 = word1.size(), n2 = word2.size();
            return solve(n1, n2, word1, word2);
        }
    };