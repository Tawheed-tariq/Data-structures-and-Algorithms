// https://www.youtube.com/watch?v=ExY8svHF_Eo
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0, maxFreq = 0, maxWindow = 0;

        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;

            maxFreq = max(maxFreq, mp[s[right]]);
            int windowSize = right - left + 1;

            if(windowSize - maxFreq > k){
                mp[s[left++]]--;
            }

            windowSize = right - left + 1;
            maxWindow = max(maxWindow, windowSize);

        }
        return maxWindow;
    }
};