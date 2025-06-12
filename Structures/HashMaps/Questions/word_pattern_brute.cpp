class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        string temp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                vec.push_back(temp);
                temp = "";
                continue;
            }else if(i == s.size() -1){
                temp.push_back(s[i]);
                vec.push_back(temp);
            }
            temp.push_back(s[i]);
        }

        unordered_map<char, string> mp;
        unordered_map<string, char> mapp;

        if(pattern.size() != vec.size()) return false;

        for(int i = 0; i < vec.size(); i++){
            if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != vec[i]) return false;
            }else{
                mp[pattern[i]] = vec[i];
            }
        }


        for(int i = 0; i < vec.size(); i++){
            if(mapp.find(vec[i]) != mapp.end()){
                if(mapp[vec[i]] != pattern[i]) return false;
            }else{
                mapp[vec[i]] = pattern[i];
            }
        }

        return true;
    }
};