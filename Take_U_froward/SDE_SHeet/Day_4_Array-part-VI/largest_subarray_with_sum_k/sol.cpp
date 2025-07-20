class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int len = 0, sum = 0;
        unordered_map<int, int> prefix_sum;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(sum == k) len = i+1;

            if(prefix_sum.find(sum-k) != prefix_sum.end())
                len = max(len, i - prefix_sum[sum-k]);

            if(prefix_sum.find(sum) == prefix_sum.end())
                prefix_sum[sum] = i;
        }
        return len;
    }
};
