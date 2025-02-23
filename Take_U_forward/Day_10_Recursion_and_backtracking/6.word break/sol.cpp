#include <bits/stdc++.h> 

void solve(string &s, vector<string> &dictionary,vector<string> &ans, string temp, int strt){
    if(strt == s.size()){
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    //generate all possibilities from strt to size
    for(int i = strt; i< s.size(); i++){
        string word = s.substr(strt , i-strt+1);
        if(find(dictionary.begin(), dictionary.end(), word) != dictionary.end()){
            solve(s, dictionary, ans, temp+word+" ", i+1);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string temp;
    solve(s, dictionary, ans, temp, 0);
    return ans;
}