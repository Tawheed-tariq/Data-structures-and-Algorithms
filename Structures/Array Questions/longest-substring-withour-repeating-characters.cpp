class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charSet.count(s[right]) == 0) { //if new element encoutered which is not in set
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            } else {
                //if element is present in set remove element and increment left pointer
                while (charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                //insert element to set
                charSet.insert(s[right]);
            }
        }
        
        return maxLength;
    }
};