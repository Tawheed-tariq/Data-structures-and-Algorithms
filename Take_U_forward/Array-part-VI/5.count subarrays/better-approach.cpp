int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        int x  = 0;
        for(int j = i; j < A.size(); j++){
                x ^= A[j];
            
            if(x==B)
                count++;
        }
    }
    return count;
}
