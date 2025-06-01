// https://www.youtube.com/watch?v=uwOz378g3ew&list=PLpIkg8OmuX-I-t2eiSxfO0UjiLhmNGfon&index=3
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1, 0);
        for(int i = 1; i <= n; i++){
            if(i%2 == 0) 
                arr[i] = arr[i/2];
            else
                arr[i] = arr[i/2] +1;
        }
        return arr;
    }
};