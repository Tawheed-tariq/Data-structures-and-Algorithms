class Solution {
public:

    void solve(int i, string digits, string &temp, vector<string> &res, unordered_map<char, string> mp){
        if(i == digits.size()){
            res.push_back(temp);
            return;
        }

        string str = mp[digits[i]];

        for(char &ch: str){
            temp.push_back(ch);
            solve(i+1, digits, temp, res, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> res;
        string temp = "";
        solve(0, digits, temp, res,  mp);

        return res;
    }
};