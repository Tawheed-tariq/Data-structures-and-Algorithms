#include<iostream>
#include<math.h>
using namespace std;
int binary_to_decimal(int);
int main(){
    int binary, decimal;
    cout << "Enter a binary: ";
    cin >> binary;
    decimal = binary_to_decimal(binary);
    cout << "decimal of " << binary << " is " << decimal;

}
int binary_to_decimal(int binary){
    int ans = 0 , digit, i = 0;
    while (binary!=0)
    {
        digit = binary %10;
        if(digit == 1)
            ans += pow(2,i);
        i++;
        binary /= 10;
    }
    return ans;
    
}