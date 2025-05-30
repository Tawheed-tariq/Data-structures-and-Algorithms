class Solution {
public:
    int beautySum(string s) {
        int total = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_map<char, int> mp;
            for(int j = i; j < s.size(); j++){
                mp[s[j]]++;

                int minFreq = INT_MAX, maxFreq = INT_MIN;

                for(auto ele: mp){
                    minFreq  = min(minFreq, ele.second);
                    maxFreq = max(maxFreq, ele.second);
                }
                total += maxFreq - minFreq;
            }
        }
        return total;
    }
};