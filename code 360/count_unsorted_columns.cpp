#include <bits/stdc++.h> 
using namespace std;


int countColumns(vector<string> &strings)
{
    int count = 0;
    int n = strings.size();
    if(n == 0) return 0;
    int cols = strings[0].size();
    for(int i = 0; i < cols; i++){
        int prev = strings[0][i] - 'a';
        for(int j = 1; j < n; j++){
            int temp = strings[j][i] - 'a';
            if(temp < prev){
                count++;
                break;
            }
            prev = temp;
        }
    }
    return count;
}
