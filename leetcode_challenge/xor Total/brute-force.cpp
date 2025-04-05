class Solution {
    public:
        int xorTotal(vector<int> arr){
            int ans = 0;
            for(int i =0; i < arr.size(); i++){
                ans ^= arr[i];
            }
            return ans;
        }
        void solve(vector<int> &nums, vector<int> &output, int ind, int &sum){
            if(ind >= nums.size()){
                sum += xorTotal(output);
                return;
            }
    
            solve(nums, output, ind+1, sum); //do not select currect element
            output.push_back(nums[ind]); 
            solve(nums, output, ind+1, sum); //select the current element
        }
        int subsetXORSum(vector<int>& nums) {
            int sum = 0;
            vector<int> output;
            solve(nums, output, 0, sum);
            return sum;
        }
    };