#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&a, int start, int mid , int end, int &count){
    int i = start;
    int j = mid+1;
    int k = start;
    vector<int>temp(end-start+1);
    while(i<=mid && j <=end){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j];
            long long num = a[j];
            num = a[j]*2;
            if(a[i] > num){
                count++;
            }
            j++;
        }
    }
        while( i <= mid) temp[k++] = a[i++];
        while(j <= end) temp[k++] = a[j++];
        for(int i = start; i<=end; i++){
		a[i] = temp[i];
	}
    }

void divide(vector<int>&a, int start, int end,int &count){
    if (start >= end) return;
    
   int mid = start+(end-start)/2;
   divide(a, start, mid,count);
   divide(a,mid+1, end,count);
   merge(a, start,mid, end,count);

}

int main(){
    int n;
    cout<<"enter the number";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the array ";
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    int count = 0;
    divide(nums,0,n-1,count);

    cout<<count;

}








/*
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int start, int mid, int end, int &count) {

    // 🔹 Count reverse pairs
    int j = mid + 1;
    for (int i = start; i <= mid; i++) {
        while (j <= end && (long long)a[i] > 2LL * a[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // 🔹 Merge step
    vector<int> temp;
    int i = start;
    j = mid + 1;

    while (i <= mid && j <= end) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= end) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++) {
        a[start + k] = temp[k];
    }
}

void divide(vector<int>& a, int start, int end, int &count) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    divide(a, start, mid, count);
    divide(a, mid + 1, end, count);
    merge(a, start, mid, end, count);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int count = 0;
    divide(nums, 0, n - 1, count);

    cout << count;
}
*/