class Solution {
    public:
        string reverseWords(string s) {
            vector<string> ans;
            string str = "";
            int i = 0, n = s.size();
            while( i < s.size()){
                while( i < s.size() && s[i] == ' ')
                    i++;
                while( i < s.size() && s[i] != ' ')
                    str.push_back(s[i++]);
                if(str != "")
                    ans.push_back(str);
                str = "";
            }
            str = "";
            for(int i = ans.size() - 1; i >= 0; i--){
                str += ans[i];
                if(i != 0)
                    str.push_back(' ');
            }
            return str;
        }
    };