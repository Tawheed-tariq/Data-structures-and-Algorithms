//prefix array
class NumArray {
    public:
        vector<int> arr;
        NumArray(vector<int>& nums) {
            arr.push_back(nums[0]);
    
            for(int i = 1; i < nums.size(); i++){
                arr.push_back(arr[i-1] + nums[i]);
            }
        }
        
        void update(int index, int val) {
            int prev = arr[index];
            if(index == 0)
                arr[index] = val;
            else
                arr[index] = arr[index-1] + val;
            for(int i = index+1; i < arr.size(); i++){
                int temp = arr[i];
                arr[i] = arr[i] - prev + arr[i-1];
                prev = temp;
            }
        }
        
        int sumRange(int left, int right) {
            if(left == 0)
                return arr[right];
            return arr[right] - arr[left-1];
        }
    };
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * obj->update(index,val);
     * int param_2 = obj->sumRange(left,right);
     */