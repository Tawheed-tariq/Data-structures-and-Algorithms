int LPS(string str){
    int pre = 0;
    int suf = 1;
    int n = str.size();
    vector<int> arr(str.size(), 0); //arr[0] is always 0

    while(suf < str.size()){
        if(str[suf] == str[pre]){
            pre++;
            arr[suf] = pre;
            suf++;
        }else{
            if(pre == 0){
                //we are at first element
                arr[suf] = 0;
                suf++;
            }else{
                pre = arr[pre-1]; //go to previous matched value
            }
        }
    }
    return arr[n-1];
}

int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    
    A = A + '#' + B;
    return B.size() - LPS(A);
}
