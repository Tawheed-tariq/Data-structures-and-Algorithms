// https://www.youtube.com/watch?v=LeEvAlEm_DY
class Solution {
    #define ll long long
public:
    long long countGood(vector<int>& nums, int k) {
        ll n = nums.size(), left = 0, right = 0;
        unordered_map<ll, ll> freq;
        ll equal_pairs = 0, good_subarrays = 0;

        while(left < n){
            while(right < n && equal_pairs < k){
                freq[nums[right]]++;
                equal_pairs += freq[nums[right]] - 1;
                right++;
            }

            if(equal_pairs >= k){
                good_subarrays += n - right +1;
            }


            //remove the left item
            freq[nums[left]]--;
            equal_pairs -= freq[nums[left]];
            left++;
        }
        return good_subarrays;
    }
};