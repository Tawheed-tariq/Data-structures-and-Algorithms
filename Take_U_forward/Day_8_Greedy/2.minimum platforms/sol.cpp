class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          sort(arr.begin(), arr.end());
          sort(dep.begin(), dep.end());
          
          int ans = 1, count = 1, i = 1, j = 0, n = arr.size();
          while(i < n && j < n){
              if(arr[i] <= dep[j]){
                  count++;
                  i++;
              }
              else{
                  count--;
                  j++;
              }
              ans = max(ans, count);
          }
          return ans;
      }
  };