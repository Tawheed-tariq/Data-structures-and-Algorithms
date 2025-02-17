class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            int water = 0;
            for(int i = 0; i < n; i++){
                int leftMax = 0, rightMax = 0, j = i;
                while( j >= 0){
                    leftMax = max(leftMax, height[j]), j--;
                }
                j = i;
                while(j < n){
                    rightMax = max(rightMax, height[j]), j++;
                }
                water += min(leftMax, rightMax) - height[i];
            }
            return water;
        }
    };