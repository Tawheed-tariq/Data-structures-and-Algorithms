class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char,int> mp;
            mp['I'] = 1;
            mp['V'] = 5;
            mp['X'] = 10;
            mp['L'] = 50;
            mp['C'] = 100;
            mp['D'] = 500;
            mp['M'] = 1000;
    
            int sum = 0;
            char prev;
            for(int i = 0; i < s.size(); i++){
                if(mp[prev] && mp[prev] < mp[s[i]]){
                    sum += mp[s[i]] - 2*mp[prev];
                }else{
                    sum += mp[s[i]];
                } 
                prev = s[i];
            }
            return sum;
        }
    };