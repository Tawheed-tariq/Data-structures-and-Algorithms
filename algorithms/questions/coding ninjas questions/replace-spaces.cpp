//have to replace every space in a string with "@40"

#include<iostream>
using namespace std;
string replace_spaces(string s){
    string str = "";
    for(int i=0;i < s.length(); i++){
        if(s[i] != ' ')
            str.push_back(s[i]);
        else{
            str.push_back('@');
            str.push_back('4');
            str.push_back('0');
        }
    }
    return str;
}
int main(){
    cout << replace_spaces("tawheed tariq bhat");
}