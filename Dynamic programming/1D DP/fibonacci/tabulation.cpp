#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int fib(int n, vector<int> &dpArray){
        //base cases
        dpArray[0] = 0;
        dpArray[1]= 1;
        for(int i = 2; i <= n; i++){
                dpArray[i] = dpArray[i-1] + dpArray[i-2];
        }
        return dpArray[n];
}


int main()
{
        int n;
        cin >> n;
        vector<int> dpArray(n+1);
        for(int i = 0; i < n+1; i++){
                dpArray[i] = -1;
        }
        cout << fib(n, dpArray) << endl;
}

