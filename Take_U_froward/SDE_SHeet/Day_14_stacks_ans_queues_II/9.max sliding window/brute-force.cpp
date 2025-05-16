#include <bits/stdc++.h> 
int minSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    int maxi = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(!dq.empty() && dq.front() == i-k) dq.pop_front(); //dq.front( ) is out of window
        while(!dq.empty() && nums[dq.back()] >= nums[i])
            dq.pop_back();
        
        dq.push_back(i);
        if(i >= k-1){
            maxi = max(maxi, nums[dq.front()]);
        }
    }
    return maxi;
}
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> res;
    for(int i = 1; i <= n; i++){
        res.push_back(minSlidingWindow(a, i));
    }
    return res;
}