//both methods used , remainder method and also bits method
#include<iostream>
#include<math.h>
using namespace std;
int decimal_to_binary_1(int);
int decimal_to_binary_2(int);
int main(){
    int decimal, binary;
    cout << "Enter an decimal: ";
    cin >> decimal;
    binary = decimal_to_binary_2(decimal);
    cout << "decimal to binary gives: " << binary;
}
int decimal_to_binary_1(int decimal){
    //remainder method
    int ans = 0;
    int rem, i = 0;
    while (decimal != 0)
    {
        rem = decimal % 2;
        ans += pow(10,i)*rem;
        decimal /= 2;
        i++;
    }
    return ans;
}
int decimal_to_binary_2(int decimal){
    //bits method
    int bit, ans = 0, i = 0;
    while (decimal != 0)
    {
        bit = decimal & 1;
        ans += pow(10,i)*bit;
        decimal = decimal >> 1;
        i++;
    }
    return ans;
    
}