 // https://www.codechef.com/practice/course/2-star-difficulty-problems/DIFF1500/problems/MTYFRI

 /* approach -> first we will divide the array into two parts one for motu 
 and one for tomu then we will sort the motu part in descending order and 
 tomu part in ascending order then we will swap the elements of both the parts
  until we have done k swaps or we have reached the end of any of the parts then
   we will calculate the score of both motu and tomu and compare them if tomu 
   score is greater than motu score then we will print yes otherwise no
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here'
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    vector<int> arr(n);
	    for(int i = 0; i<n; i++){
	        cin>>arr[i];
	    }
	    vector<int>motu;
	    vector<int>tomu;
	    for(int i = 0;i<n;i++){
	        if(i%2 == 0){
	            motu.push_back(arr[i]);
	        }else{
	            tomu.push_back(arr[i]);
	        }
	    }
	    sort(motu.begin(), motu.end(), greater<int>());
	    sort(tomu.begin(),tomu.end());
	    
	    int motuSize = motu.size();
	    int tomuSize = tomu.size();
	    
	   //     int count = 0;
    // while(count < k && count < motuSize && count < tomuSize){
    //      for(int i = 0; i < k; i++){
 	  //      if(motu[i] > tomu[i]){
 	  //          swap(motu[i],tomu[i]);
 	  //          count++;
	   //     }
    //      }
    //   }
    
    for(int i = 0; i < min({k, motuSize, tomuSize}); i++){
    if(motu[i] > tomu[i]){
        swap(motu[i], tomu[i]);
    }
}
        
	long long motuScore = 0;
	long long tomuScore = 0;
	for(int i = 0; i<motuSize; i++){
	    motuScore += motu[i];
	}
	for(int i = 0; i<tomuSize; i++){
	    tomuScore += tomu[i];
	}
	if(tomuScore > motuScore){
	    cout<<"yes"<<"\n";
	}else{
	    cout<<"no"<<"\n";
	}
  }
}
