#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int>heap;
public: 
    MaxHeap(vector<int>&arr){    
        heap = arr;
        int n = heap.size();
        for(int i = n/2-1; i>=0; i--){
            heapify(i);
        }
    }

    void heapify(int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left < heap.size() && heap[left] > heap[largest]){
            largest = left;
        }
        if(right < heap.size() && heap[right] > heap[largest]){
            largest = right;
        }
        if(largest != i){
            swap(heap[i],heap[largest]);
            heapify(largest);
        }
    }

    void insert(int val){
        heap.push_back(val);
        int i = heap.size()-1;
        while(i > 0){
            int parent = (i-1)/2;
            if(heap[parent] < heap[i]){
                swap(heap[parent],heap[i]);
                i = parent;
            }else{
                break;
            }
        }
    }

    void print(){
        for(int i : heap){
            cout<<i<<" ";
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of elements in the array ";
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
}