class Solution {
    public:
      int maxLen(vector<int>& arr) {
          int len = 0;
          for(int i = 0; i < arr.size(); i++){
              int sum = 0;
              for(int j = i; j < arr.size(); j++){
                  sum += arr[j];
                  if(sum == 0)
                      len = max(len, j-i+1);
              }
          }
          return len;
      }
  };