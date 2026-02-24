// https://www.codechef.com/practice/course/2-star-difficulty-problems/DIFF1500/problems/HOTEL

/* Approach: We can iterate through each time unit from 1 to 1000 and count the number 
of guests present in the hotel at that time. We can keep track of the maximum count of 
guests at any time unit, which will give us the minimum number of rooms required to accommodate
 all guests.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	   int n;
	   cin>>n;
	   vector<int>arrive(n);
	   for(int i = 0; i<n; i++){
	       cin>>arrive[i];
	   }
	   vector<int>depart(n);
	   for(int i = 0; i<n; i++){
	       cin>>depart[i];
	   }
	   int maxi = 0;
	   for(int i = 1; i<=1000; i++){
	       int count = 0;
	       for(int j = 0; j<n; j++){
	           if(arrive[j]<=i && i < depart[j]){
	               count++;
	           }
	       }
	       maxi = max(maxi,count);
	   }
	   cout<<maxi<<"\n";
	}
    
}
