// count the number of zeros, ones and twos and then fill the array with the count of zeros, ones and twos
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int zero = 0, one = 0, two = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0)
                    zero++;
                else if(nums[i] == 1)
                    one++;
                else
                    two++;
            }
    
            int ind = 0;
            int count = 0;
            while(count < zero){
                nums[ind] = 0;
                ind++;
                count++;
            }
            count  = 0;
            while(count < one){
                nums[ind] = 1;
                ind++;
                count++;
            }
            count  = 0;
            while(count < two){
                nums[ind] = 2;
                ind++;
                count++;
            }
        }
    };