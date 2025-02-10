vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    long long diff = (n * (n + 1)) >> 1; // Right shift for division by 2
    long long squareDiff = 0;

    for (int i = 1; i <= n; i++) {
        long long v = A[i - 1]; // Direct access using [] (0-indexed)
        long long k = i;
        diff -= v;

        long long tmp = (k + v) * (k - v);
        squareDiff += tmp;
    }

    // Check for potential division by zero. Throw exception or handle it appropriately.
    if (diff == 0) {
       throw std::runtime_error("Division by zero error. Check input data.");
    }
   
    long long y = (squareDiff / diff + diff) / 2;
    long long x = y - diff;

    std::vector<int> out;
    out.push_back(static_cast<int>(x)); // static_cast for type conversion
    out.push_back(static_cast<int>(y));
    return out;
}
