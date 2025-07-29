class Solution {
  public:
  long long pow(int x, int n){
    if(n == 0) return 1;
    if(n == 1) return x;

    long long ans = pow(x, n/2);
    if(n%2 == 0) return ans*ans;
    return ans*ans*x;
  }
    int nthRoot(int N, int M) {
        // Code here
        int low = 0, high = M;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long ans = pow(mid, N);
            if(ans == M) return mid;
            else if(ans > M) high = mid -1;
            else low = mid+1;
        }
       return -1;
    }
};


