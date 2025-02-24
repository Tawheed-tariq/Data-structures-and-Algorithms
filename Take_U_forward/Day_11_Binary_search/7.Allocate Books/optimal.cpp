int countStudents(vector<int> &A, int pages){
    int n = A.size(), students = 1, pagesStudent = 0;
    for(int i = 0; i< n; i++){
        if(pagesStudent + A[i] <= pages)
            pagesStudent += A[i];
        else{
            students++;
            pagesStudent = A[i];
        }
    }
    return students;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size())
        return -1;
    int low = *max_element(A.begin(), A.end());
    int high = 0;
    for(int i = 0; i < A.size(); i++){
        high+=A[i];
    }
    
    while(low <= high){
        int mid = low + (high - low)/2;
        int students = countStudents(A, mid);
        if(students > B)
            low = mid+1;
        else 
            high = mid -1;
    }
    return low;
}
