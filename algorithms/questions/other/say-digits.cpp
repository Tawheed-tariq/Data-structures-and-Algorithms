#include<iostream>
#include<string>
using namespace std;
void say_digit(int);
int main(){
       say_digit(410);
}

void say_digit(int n){
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(n >0 ){
    int digit = n % 10;
    say_digit(n/10);
    cout << arr[digit] << endl;
    }
}
