class Solution {
    public:
      int maxLen(vector<int>& arr) {
          int len = 0, sum = 0;
          unordered_map<int, int> mp;
          for(int i = 0; i < arr.size(); i++){
              sum += arr[i];
              if(sum ==0)
                  len = i+1;
              else if(mp.find(sum) != mp.end()) // current sum is seen before which concludes that it’s a zero subarray.
                  len = max(len, i - mp[sum]);
              else
                  mp[sum] = i;
          }
          return len;
      }
  };