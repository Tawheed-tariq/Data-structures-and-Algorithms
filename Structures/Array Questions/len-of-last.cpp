class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp = "";
        int len = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }else{
                if(temp.size() > 0)
                    len = temp.size();
                temp = "";
            }
        }
        if(temp.size() > 0)
            len = temp.size();
        return len;
    }
};