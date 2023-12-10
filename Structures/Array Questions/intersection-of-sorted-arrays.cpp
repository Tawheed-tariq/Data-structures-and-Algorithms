#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int index1 = 0, index2 = 0;
	vector<int> ans;
	while(index1 < n && index2 < m){
		if(arr1[index1] == arr2[index2]){
			int ele = arr1[index1];
			ans.push_back(ele);
			index1++;
			index2++;
		}else if(arr1[index1] < arr2[index2]){
			index1++;
		}else{
			index2++;
		}
	}
	return ans;
}