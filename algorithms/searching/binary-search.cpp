#include<iostream>
using namespace std;
int search(int *, int ,int);
int binary_search(int *,int, int, int);
int main(){
    int n = 6,  arr[n] = {1,2,4,6,8,9}, key = 8;
    cout << binary_search(arr,0, n, key);

}

//iterative approach
int search(int *arr, int n , int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(arr[mid] == key)
            return mid;
        else if(key > arr[mid])
            start = mid +1;
        else if(key < arr[mid])
            end = mid -1;
        mid = start + (end - start)/2;
    }
    return -1;
}

//recursive approach
int binary_search(int arr[], int start, int end, int key){
    int mid = start + (end- start)/2;
    if(start > end)
        return -1;
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return binary_search(arr, 0, mid-1, key);
    else 
        return binary_search(arr, mid+1, end, key); 
}