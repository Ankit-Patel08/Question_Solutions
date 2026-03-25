#include<bits/stdc++.h>
using namespace std;

void printNum(int n){
    if(n == 0){
        cout<< 0;
        return;
    }
    cout<<n<< " ";    // to print it in descending order  
    printNum(n-1);
    cout<<n<< " ";     // to print it in acending order
}


void printNto1(int n){             //   ascending order  by using backtracking 
  if(n < 1) return;
  printNto1(n-1);
  cout<<n<<" ";
}


void sumFirstN(int n, int ans){           // parametarised way
    if(n < 1) {
        cout<< ans;
        return;
    }
    sumFirstN(n-1,ans+n);
}


int SumFirstNoPara(int n){           // non parametarised way 
    if(n < 1) return 0;

    return n+SumFirstNoPara(n-1);
}


void reverse(vector<int>&arr, int left , int right){     // reversing the array by using two pointer
    if(left >= right) return;
    swap(arr[left], arr[right]);
    reverse(arr,left+1, right-1);
}   

bool pelindrom(string s, int start , int end){    // is pelindrom
    if(start >= end) return true;
    if(s[start] == s[end]){
       return pelindrom(s,start+1, end-1);
    }else{
        return false;
    }
}

int main(){
    // int n;
    // cout<<"Enter the number";
    // cin>>n;
    
   // printNum(n);
   // printNto1(n);
  // int ans = 0;
  // sumFirstN(n,ans);

  //cout<< SumFirstNoPara(n);

// vector<int> arr = {1,2,3,4,5,6};
// reverse(arr,0,5);

// for(int a:arr) cout<< a <<" ";

string s;
cin>>s;
int n = s.size();
cout<<pelindrom(s,0,n-1);

}