#include<iostream>
using namespace std;

int find_pivot(int arr[], int n){
    int start = 0, end = n-1;
    int mid = start + (end - start)/2;
    while (start<end)
    {
        if(arr[mid]>=arr[0])
            start = mid +1;
        else
            end =mid;
        mid = start + (end -start)/2;
    }
    return start;
}

int search(int arr[], int start, int end , int key){
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
int search(int arr[], int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = find_pivot(arr,n);
    if(k >= arr[pivot] && k <= arr[n-1])
        return search(arr,pivot,n-1,k);
    else 
        return search(arr,0,pivot-1,k);
        
}
