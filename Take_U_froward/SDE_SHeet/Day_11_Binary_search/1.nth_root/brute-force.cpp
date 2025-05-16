long long pow(int x, int n){
    if(n == 0)
      return 1;
    if(n == 1)
      return x;
    long long ans = pow(x, n/2);
    if(n%2 ==0){
      return ans*ans;
    }
    return ans*ans*x;
  }
  
  int NthRoot(int n, int m) {
    for(int i = 1; i <= m; i++){
      long long val = pow(i, n);
      if(val == m*1ll) return i;
      else if(val > m*1ll) return -1;
    }
  }