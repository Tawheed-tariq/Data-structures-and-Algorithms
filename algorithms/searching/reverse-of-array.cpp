#include<iostream>
using namespace std;
void swap(int *, int *);
void reverse(int *, int);
int main(){
    int n = 7, arr[n] ={1,2,3,4,5,6,7};
    reverse(arr,n);
    for(int i = 0; i<n; i++){
        cout << *(arr+i) << "\t";
    }

}

void reverse(int *arr, int n){
    for(int i = 0; i<n/2; i++){
        swap(*(arr+i), *(arr+(n-i-1)));
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}