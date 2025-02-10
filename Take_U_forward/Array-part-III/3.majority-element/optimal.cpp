class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0, candidate = 0;
            for(auto x : nums){
                if(count == 0)
                    candidate = x;
                if(x == candidate)
                    count++;
                else
                    count--;
            }
            return candidate;
        }
    };