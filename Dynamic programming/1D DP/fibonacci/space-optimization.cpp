#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin >> n;
        int prev1 = 1;
        int prev = 0;
        if(n == 0){
                cout << prev << endl;
                return 0;
        }
        for(int i = 2; i <=n ; i++){
                int curr = prev1 + prev;
                prev = prev1;
                prev1 = curr;
        }
        cout << prev1 << endl;
}