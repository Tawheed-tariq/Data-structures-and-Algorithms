#include<bits/stdc++.h>
using namespace std;


int fib(int n, vector<int> &dpArray){
        if(n <= 1)
                return n;
        if(dpArray[n] != -1) //memoization
                return dpArray[n];
        dpArray[n] = fib(n-1, dpArray) + fib(n-2, dpArray);
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

