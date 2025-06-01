// https://www.youtube.com/watch?v=Gx4-uOkopMA&list=PLpIkg8OmuX-I-t2eiSxfO0UjiLhmNGfon&index=1
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result1 = (a | b) ^ c;

        int result2 = a& b;

        int result = result1 & result2;

        return __builtin_popcount(result1) + __builtin_popcount(result);
    }
};