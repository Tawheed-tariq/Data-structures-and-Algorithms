class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0, right = n- k- 1, ans = INT_MIN;
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        while(right < n){
            int currSum = 0;
            for(int i =left; i <= right; i++)
                currSum += cardPoints[i];
            ans = max(ans, total - currSum);
            left++;
            right++;
        }
        return ans;
    }
};