class Solution {
    public:
        bool isPalindrome(string str){
            string new_str = str;
            reverse(str.begin(), str.end());
            return new_str == str;
        }
        int solve(int ind, string s, string str){
            if(ind >= s.size()){
                return isPalindrome(str)? str.length() : 0;
            }
    
            int take = solve(ind+1, s, str + s[ind]);
            int notTake = solve(ind+1, s, str);
    
            return max(take, notTake);
        }
        int longestPalindromeSubseq(string s) {
            if(isPalindrome(s)) return s.size();
            return solve(0, s, "");
        }
    };