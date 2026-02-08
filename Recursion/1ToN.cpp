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

void printEven(int n){
    


}

int main(){
    int n;
    cout<<"Enter the number";
    cin>>n;

    printNum(n);


}