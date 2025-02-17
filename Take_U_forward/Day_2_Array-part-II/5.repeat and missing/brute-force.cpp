vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n1 = A.size();
    long long sum = n1 * (n1 +1) >> 1; // Right shift for division by 2
    long long sqSum = n1 * (n1 +1) * (2*n1 + 1)/6;
    long long arr_sum = 0;
    long long arr_sq_sum = 0;
    for (int i = 0; i < n1; i++){
        arr_sum += A[i];
        arr_sq_sum += A[i]*A[i];
    }
    
    long long X = sum - arr_sum;
    long long Y = sqSum - arr_sq_sum;
    
    long long b = (X + Y/X)/2;
    long long a = b - X;
    std::vector<int> out;
    out.push_back(static_cast<int>(a)); // static_cast for type conversion
    out.push_back(static_cast<int>(b));
    return out;
}
