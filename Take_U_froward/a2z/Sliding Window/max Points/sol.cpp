class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int leftSum = 0, rightSum = 0;

        for(int i = 0; i < k; i++) leftSum += nums[i];

        int totalSum = leftSum;

        int right = nums.size() - 1;

        for(int left = k-1; left >= 0; left--){
            leftSum -= nums[left];
            rightSum += nums[right];
            right--;

            totalSum = max(totalSum, leftSum+rightSum);
        }

        return totalSum;
    }
};