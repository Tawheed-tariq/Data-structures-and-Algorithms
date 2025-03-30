#include <bits/stdc++.h> 
string stringSum(string &num1, string &num2) {
    int n1 = num1.size()-1, n2 = num2.size() -1;
    int carry = 0;
    string res = "";
    while(n1 >= 0 || n2 >= 0 || carry){
        int c1 = n1 >= 0 ? num1[n1--] - '0': 0;
        int c2 = n2 >= 0? num2[n2--] -'0': 0;
        int sum = c1+c2+carry;
        carry = sum / 10;
        res.push_back(char(sum%10 + '0'));
    }
    reverse(res.begin(), res.end());
    return res;
}