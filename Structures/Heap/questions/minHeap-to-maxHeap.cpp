#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void heapifyMax(vector<int>&arr, int size, int i ){
    int largest = i, left = 2*i + 1 , right = 2*i + 2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapifyMax(arr, size, largest);
    }
}
vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	for(int i = n-1; i >= 0; i--){
		heapifyMax(arr, n, i);
	}
	return arr;
}