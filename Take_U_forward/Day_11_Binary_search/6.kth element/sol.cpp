class Solution {
    public:
      vector<int> merge(vector<int>& nums1, vector<int>& nums2){
          int ind1 = 0, ind2 = 0, m = nums1.size(), n =nums2.size();
          vector<int> ans;
  
          while(ind1 < m && ind2 < n){
              if(nums1[ind1] < nums2[ind2])
                  ans.push_back(nums1[ind1++]);
              else
                  ans.push_back(nums2[ind2++]);
          }
  
          while(ind1 < m){
              ans.push_back(nums1[ind1++]);
          }
          while(ind2 < n){
              ans.push_back(nums2[ind2++]);
          }
          return ans;
      }
      int kthElement(vector<int>& a, vector<int>& b, int k) {
          vector<int> ans = merge(a, b);
          return ans[k-1];
      }
  };
  