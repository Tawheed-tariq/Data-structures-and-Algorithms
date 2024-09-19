#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        for(int i = 0; i < timeSeries.size(); i++){
            int strt = timeSeries[i];
            int end = timeSeries[i] + duration -1;
            if(i < timeSeries.size()-1 && timeSeries[i+1] <= end){
                ans += timeSeries[i+1] - strt;
            }
            else{
                ans += end - strt +1;
            }
        }
        return ans;
    }
};