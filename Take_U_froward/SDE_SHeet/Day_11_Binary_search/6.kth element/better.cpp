class Solution {
    public:
      int merge(vector<int>& nums1, vector<int>& nums2, int k){
          int ind1 = 0, ind2 = 0, m = nums1.size(), n =nums2.size();
          int cnt;
  
          while(ind1 < m && ind2 < n){
              if(nums1[ind1] < nums2[ind2]){
                  if(cnt == k-1) return nums1[ind1];
                  ind1++;
                  cnt++;
              }
              else{
                  if(cnt == k-1) return nums2[ind2];
                  ind2++;
                  cnt++;
              }
          }
  
          while(ind1 < m){
              if(cnt == k-1) return nums1[ind1];
              ind1++;
              cnt++;
          }
          while(ind2 < n){
              if(cnt == k-1) return nums2[ind2];
              ind2++;
              cnt++;
          }
          return -1;
      }
      int kthElement(vector<int>& a, vector<int>& b, int k) {
          int ans = merge(a, b, k);
          return ans;
      }
  };