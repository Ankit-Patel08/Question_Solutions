
// problem link: https://www.codechef.com/practice/course/2-star-difficulty-problems/DIFF1500/problems/PMA
/*
Approach -> we will first calculate the sum of the array by adding the absolute
value of the elements at even indices and subtracting the absolute
value of the elements at odd indices then we will find the minimum
absolute value at even indices and maximum absolute value at odd indices
then we will check if the maximum absolute value at odd indices is greater
than minimum absolute value at even indices then we will add 2 times
the difference of maximum absolute value at odd indices and 
minimum absolute value at even indices to the sum and print the final sum


my mistake -> i was solving this by using priority queue, that increased the time 
complexity to O(nlogn) but the optimal solution is O(n) as we can find
 the minimum and maximum in one pass

 why prioriy queue is not optimal -> because we only need to find the minimum and 
 maximum once and we can do that in O(n) time by iterating through the array
once but if we use priority queue then we will have to insert all
the elements in the priority queue which will take O(nlogn) time and
then we will have to extract the minimum and maximum which will take 
O(logn) time each so the overall time complexity will be O(nlogn) which
is not optimal for this problem

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
	    vector<long long>nums(n);
	    long long sum = 0;
	    for(int i = 0; i<n; i++){
	        cin>>nums[i];
	        
	        if(i % 2 == 0){
	            sum = sum+abs(nums[i]);
	        }else{
	            sum = sum-abs(nums[i]);
	        }
	    }
	    
        long long minEven = LLONG_MAX;
        long long maxOdd = LLONG_MIN;

	    for(int i = 0; i<n; i++){
	        
	        long long val = abs(nums[i]);

	        if(i % 2 == 0){
	            minEven = min(minEven,val);
	        }else{
	            maxOdd = max(maxOdd, val);
	        }
	    }
	 
	   if(maxOdd > minEven){
	       sum = sum+2*(maxOdd-minEven);
	   }
	   cout<<sum<<"\n";
	}

}
