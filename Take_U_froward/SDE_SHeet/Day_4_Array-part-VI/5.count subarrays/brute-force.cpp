int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        for(int j = i; j < A.size(); j++){
            int x  = 0;
            for(int k = i; k <= j; k++){
                x ^= A[k];
            }
            
            if(x==B)
                count++;
        }
    }
    return count;
}
