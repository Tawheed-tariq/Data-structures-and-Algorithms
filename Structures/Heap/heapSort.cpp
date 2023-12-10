#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapifyMax(int *, int, int);



//for max heap
void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[1], arr[size]);
        size--;

        heapifyMax(arr, n , 1);
    }
}
void heapifyMax(int arr[], int size, int i ){
    int largest = i, left = 2*i , right = 2*i +1;

    if(left <= size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapifyMax(arr, size, largest);
    }
}