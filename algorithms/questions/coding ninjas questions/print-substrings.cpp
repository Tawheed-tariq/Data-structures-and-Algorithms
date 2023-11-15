#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(string input) {
    for(int i =0; i < input.length(); i++){
        for(int j = 0; j < input.length(); j++){
            for(int k = i; k <= j; k++){
                cout << input[k];
            }
            if(j >= i)
                cout << "\n";
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}