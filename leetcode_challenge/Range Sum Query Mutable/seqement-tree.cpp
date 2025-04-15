class NumArray {
    public:
        vector<int> seq;
        int n;
    
        void buildTree(vector<int> &nums, int pos, int left, int right){
            if(left == right){
                seq[pos] = nums[left];
                return;
            }
            int mid = (left+right)/2;
            buildTree(nums, 2*pos+1, left, mid);
            buildTree(nums, 2*pos+2, mid+1, right);
            seq[pos] = seq[2*pos+1] + seq[2*pos+2];
        }
        void updateUtil(int pos, int left, int right, int index, int val){
            //no overlap
            if(index < left || index > right)
                return;
            
            //total overlap
            if(left == right){
                if(left == index)
                    seq[pos] = val;
                return;
            }
    
            //partial overlap
            int mid = (left+right)/2;
            updateUtil(2*pos+1, left, mid, index, val);
            updateUtil(2*pos+2, mid+1, right, index, val);
            seq[pos]=seq[2*pos+1]+seq[2*pos+2];
        }
    
        int rangeUtil(int qLow, int qHigh, int low, int high, int pos){
            if(qLow <= low && qHigh >= high) return seq[pos]; //total overlap
    
            if(qLow > high || qHigh < low) return 0; //no overlap
    
            int mid = low + (high - low)/2;
            return (rangeUtil(qLow, qHigh, low, mid, 2*pos+1) + rangeUtil(qLow, qHigh, mid+1, high, 2*pos+2));
        }
        NumArray(vector<int>& nums) {
            if(nums.size() > 0){
                n = nums.size();
                seq.resize(4*n, 0);
                buildTree(nums, 0, 0, n-1);
            }
        }
        
        void update(int index, int val) {
            if(n==0) return;
    
            updateUtil(0, 0, n-1, index, val);
        }
        
        int sumRange(int left, int right) {
            if(n == 0) return 0;
    
            return rangeUtil(left, right, 0, n-1, 0);
        }
    };
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * obj->update(index,val);
     * int param_2 = obj->sumRange(left,right);
     */