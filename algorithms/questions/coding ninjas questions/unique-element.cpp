#include<iostream>
using namespace std;
int findUnique(int *, int );
int main(){
    int size = 7,  arr[size] = {2,2,1,5,1,3,5}, unique;
    unique = findUnique(arr, size);
    cout << unique;
}

int findUnique(int *arr, int size){
    int unique = 0; 
        for(int i=0; i<size; i++){
            unique = unique^arr[i];}
          return unique;
}


/*approach 

when we XOR two numbers, two cases are possible-

(1) if both numbers are equal, the result of XOR is 0.
(2) If one number is 0 and other is any number, then the result is the number.

so here, we keep XORing all the elements, and when the same element come along in the variable unique,
both the number results in 0.and the element which is left, is the unique required element

arr[5] = { 5, 8, 3, 5,8}

ITERATION-1
unique = 0^5 ----->5

ITERATION-2
unique = 5^8

ITERATION-3
unique = 5^8^3

ITERATION-4
unique = 5^8^3^5   ---> 0^8^3   ----> 8^3

ITERATION-5
unique = 8^3^8    ---> 0^3   ---->3   ---> returns the required unique element*/