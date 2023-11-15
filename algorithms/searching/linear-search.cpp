#include<iostream>
using namespace std;
bool search(int *arr, int n, int key);
bool linear_search(int *, int , int );
int main(){
    int n = 7, arr[n] = {1,2,3,4,5,6}, key = 5, result;
    cout << linear_search(arr, n , key);
    // if(result == 1)
    //     cout << "key is present in array";
    // else
    //     cout << "Key is not present in array";
}

bool search(int *arr, int n, int key){
    for(int i =0 ; i < n; i++){
        if(*(arr+i) == key)
            return 1;
    }
    return 0;
}

//recursive approach
bool linear_search(int arr[], int n, int key){
    if(n == 0)
        return false;
    if(arr[0] == key)
        return true;
    else
        return linear_search(arr+1, n-1, key);
}