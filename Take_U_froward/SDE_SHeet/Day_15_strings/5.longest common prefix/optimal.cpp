class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int n = strs.size();
            sort(strs.begin(), strs.end());
            string first = strs[0], last = strs[n-1], ans = "";
            int minLen = min(first.size(), last.size());
    
            for(int i = 0; i < minLen; i++){
                if(first[i] != last[i])
                    break;
                ans.push_back(first[i]);
            }
            return ans;
        }
    };