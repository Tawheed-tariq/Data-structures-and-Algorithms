#include <bits/stdc++.h> 
void insert(vector<int> &heap, int val){
    heap.push_back(val);
    int ind = heap.size() - 1;
    while(ind > 1){
        int parent = ind/2;
        if(heap[parent] > heap[ind]){
            swap(heap[parent], heap[ind]);
            ind = parent;
        }
        else
            return;
    }
}

int remove(vector<int> &heap){
    if (heap.size() == 1) return -1; //empty

    int val = heap[1];
    heap[1] = heap[heap.size()-1];
    heap.pop_back();
    int ind = 1;
    int size = heap.size();
    while(ind < size){
        int leftChild = 2*ind, rightChild = 2*ind +1;
        int minInd = ind;
        if(leftChild < size && heap[minInd] > heap[leftChild]){
            minInd = leftChild;
        }
        if(rightChild < size && heap[minInd] > heap[rightChild]){
            minInd = rightChild;
        }
        if(minInd == ind)
            break;
        swap(heap[ind], heap[minInd]);
        ind = minInd;
    }
    return val;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    vector<int> heap;
    heap.push_back(-1); // 1-based index

    for (int i = 0; i < q.size(); i++) {
        if (q[i][0] == 0) {
            insert(heap, q[i][1]);
        } else {
            ans.push_back(remove(heap));
        }
    }
    return ans;
}
