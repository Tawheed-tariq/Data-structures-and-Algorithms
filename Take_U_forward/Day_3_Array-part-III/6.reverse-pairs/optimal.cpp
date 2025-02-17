class Solution {
    public:
        void merge(vector<int> &nums,int s,int mid,int e, int& count){
            int j = mid+1;
            for(int i = s; i <= mid; i++){
                while(j <= e && nums[i] > 2 *(long long)nums[j])
                    j++;
                count += j - (mid+1);
            }
    
            int size = e - s +1;
            vector<int> temp(size, 0);
            int left = s, right = mid+1, k = 0;
            while(left <= mid && right <= e){
                if(nums[left] < nums[right])
                    temp[k++] = nums[left++];
                else
                    temp[k++] = nums[right++];
            }
    
            while(left <= mid){
                temp[k++] = nums[left++];
            }
            while(right <= e){
                temp[k++] = nums[right++];
            }
    
            int m = 0;
            for(int i = s; i <= e; i++){
                nums[i] = temp[m++];
            }
        }
        void mergeSort(vector<int> &nums, int s, int e, int& count){
            if(s >= e)
                return;
            int mid = s + (e-s)/2;
            mergeSort(nums, s, mid, count);
            mergeSort(nums, mid+1, e, count);
            merge(nums, s, mid, e, count);
        }
        int reversePairs(vector<int>& nums) {
            int count = 0;
            mergeSort(nums, 0, nums.size() - 1, count);
            return count;
        }
    
        
    };