class Solution {
    public:
      int median(vector<vector<int>> &mat) {
          int mini = INT_MAX, maxi = INT_MIN;
          int R = mat.size(), C= mat[0].size(), med = (R*C+1)/2;
          for(int i = 0; i < R; i++){
              mini = min(mini, mat[i][0]);
              maxi = max(maxi, mat[i][C -1]);
          }
          
          int ans;
          while(mini <= maxi){
              int mid = mini + (maxi-mini)/2;
              int freq = 0;
              
              for(int i = 0; i < R; i++){
                  freq += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
              }
              if(freq >= med){
                  maxi = mid -1;
                  ans = mid;
              } 
              else mini = mid +1;
          }
          return ans;
      }
  };