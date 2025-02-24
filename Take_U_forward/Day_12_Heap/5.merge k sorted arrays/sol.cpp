#include <bits/stdc++.h>


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int , vector<int>, greater<int> > minHeap;
    vector<int> ans;
    for(auto v:kArrays){
        for(auto ele:v){
            minHeap.push(ele);
        }
    }

    while(!minHeap.empty()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
}
