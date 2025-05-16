class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, ans;
        for(int &ele: nums){
            if(ele >= 0) pos.push_back(ele);
            else neg.push_back(ele);
        }

        for(int i = 0; i < nums.size()/2; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};