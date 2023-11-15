#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//if two or more elements contend to have max freq the return element which comes first
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> count;
    int maxFreq = 0;
    int maxAns;
    for(int i = 0; i < arr.size() ; i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }
    for(int i = 0; i< arr.size() ; i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}