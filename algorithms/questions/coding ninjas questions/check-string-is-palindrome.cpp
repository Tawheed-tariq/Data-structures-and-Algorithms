#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char convert_lower(char ch){
        if(ch >= 'A' && ch <= 'Z'){
            char temp = ch - 'A' + 'a';
            return temp;
        }
        else{
            return ch;
        }
}
bool checkPalindrome(string s)
{
    // Write your code here.
    int st = 0, e = s.length()-1;
    while(st<=e){
        s[st] = convert_lower(s[st]);
        s[e] = convert_lower(s[e]);
        if((s[st] >= 'a' && s[st] <= 'z') || (s[st] >= '0' && s[st] <= '9') ){
            if((s[e] >= 'a' && s[e] <= 'z') || (s[e] >= '0' && s[e] <= '9') ){
                if(s[st] != s[e]){
                    return 0;   
                }
                else{
                    st += 1;
                    e -= 1;
                }
            }
            else{
                e--;
            }
        }
        else{
            st++;
        }
    }
    return 1;
}
int main(){
    cout << checkPalindrome("c1 O$d@eeD o1c");
}