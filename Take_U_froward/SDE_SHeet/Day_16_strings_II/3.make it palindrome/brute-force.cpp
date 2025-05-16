int Solution::solve(string A) {
    int i = 0, j = A.size()-1, trim = j, count = 0;
    while(i < j){
        if(A[i] == A[j]){
            i++;
            j--;
        }else{
            count++;
            i=0;
            j = --trim;
        }
    }
    return count;
}
