#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int , vector<int> , greater<int> > pq;
	for(int i = 0; i < size; i++){
		if(i < K){
			pq.push(arr[i]);
		}else{
			if(arr[i] > pq.top()){
				pq.pop();
				pq.push(arr[i]);
			}
		}
	}
	return pq.top();
}