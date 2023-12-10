#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int totalPrime(int s, int e){
    vector<bool> prime(e+1, 1);
    prime[0] = prime[1] = 0;
    int count = 0;
    for(int i = s; i <= e; i++){
        if(prime[i]){
            count++;
            for(int j = i*i; j <= e; j+=i){
                prime[j] = 0;
            }
        }
    }
    return count;
}

int main() {
    int S, E;
    cout << "enter: ";
    cin >> S >> E;
    cout << totalPrime(S, E);
    return 0;
}