# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class compare{
    public:
    bool operator()(pair<int, int> a , pair<int, int> b){
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int>> , compare> minHeap;
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++; 
        }
        for(auto it: freqMap){
            minHeap.push({it.first, it.second});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return ans;
    }
};
```