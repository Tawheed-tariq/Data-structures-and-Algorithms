class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int ind1 = -1;
            int ind2 = -1;
    
            for(int i = nums.size() - 2; i>= 0; i--){
                if(nums[i] < nums[i+1]){
                    ind1 = i;
                    break;
                }
            }
    
            if(ind1 == -1)
                reverse(nums, 0);
            else{
                for(int  i = nums.size() - 1; i >= 0 ; i--){
                    if(nums[i] > nums[ind1]){
                        ind2 = i;
                        break;
                    }
                }
                swap(nums, ind1, ind2);
                reverse(nums, ind1+1);
            }
        }
    
        void swap(vector<int>& nums,int i,int j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    
        void reverse(vector<int>& nums, int strt){
            int i = strt;
            int j = nums.size() - 1;
            while(i < j){
                swap(nums, i , j);
                i++;
                j--;
            }
        }
        
    };