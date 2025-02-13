class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int count  = 0;
            for(int i = 0; i < s.length(); i++){
                unordered_map<char, bool> mp;
                int substr = 0;
                for(int j = i; j < s.length(); j++){
                    if(mp[s[j]])
                        break;
                    substr++;
                    mp[s[j]] = true;
                }
                count = max(count , substr);
            }
            return count;
        }
    };