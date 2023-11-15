#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
void heapify(vector<int> &arr, int n, int i){
    int largest = i, left = 2*i +1, right = 2*i +2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    vector<int> arr;
    for(int i = 0; i < n; i++){
        arr.push_back(arr1[i]);
    }
    for(int i = 0; i < m; i++){
        arr.push_back(arr2[i]);
    }
    int s = arr.size();
    for(int i = s/2-1; i >= 0; i--){
        heapify(arr,s,i);
    }
    return arr;
}