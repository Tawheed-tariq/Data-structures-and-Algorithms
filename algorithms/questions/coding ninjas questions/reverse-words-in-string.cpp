#include<iostream>
#include<string>
#include<vector>
using namespace std;

string reverseString(string &str){
    string s = "", st = "";
	vector<string> ans;
    for(int i = 0; i <= str.length()+1; i++){
        if (str[i] != '\0' && str[i] != ' '){
            s.push_back(str[i]);
        }
        else if(str[i] == '\0' || str[i] == ' '){
            ans.push_back(s);
            s.clear();
        }
    } 
    for(int i = ans.size()-1; i >= 0; i--){
        st += ans[i];
        if(st[st.length()-1] != ' ' && i >= 0 )
            st += " ";
    }
    return st;
}
int main(){
    string s = "welcome     to coding ninjas   ";
    cout << reverseString(s);
}
