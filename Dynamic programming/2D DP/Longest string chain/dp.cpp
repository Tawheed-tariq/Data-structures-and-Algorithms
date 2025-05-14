class Solution {
public:
    static bool comparator(string &word1, string &word2){
        return word1.size() < word2.size();
    }

    bool isPred(string &prev, string &curr){
        int m = prev.size(), n = curr.size();
        if(m >= n || n - m != 1) return false;

        int i = 0, j = 0;
        while(i < m && j < n){
            if(prev[i] == curr[j]) i++;
            j++;
        }
        return i == m;
    }

    int lis(vector<string> &words, int prev, int curr, vector<vector<int>> &dp){
        if(curr >= words.size()) return 0;

        if(dp[prev + 1][curr] != -1) return dp[prev + 1][curr];

        int take = 0;
        if(prev == -1 || isPred(words[prev], words[curr]))
            take = 1 + lis(words, curr, curr + 1, dp);

        int not_take = lis(words, prev, curr + 1, dp);

        return dp[prev + 1][curr] = max(take, not_take);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comparator);
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));  
        return lis(words, -1, 0, dp);
    }
};
