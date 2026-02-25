
// https://www.codechef.com/practice/course/2-star-difficulty-problems/DIFF1500/problems/ARRHALVES


/*
approach: 
1. We read the number of test cases, t.
2. For each test case, we read the integer n and then read an array of size 2*n.
3. We create a vector pos to store the positions of elements in the array that are greater than n.
4. We iterate through the array and whenever we find an element greater than n, we store its position (index + 1) in the pos vector.
5. We initialize a variable ans to 0, which will store the total number of moves required.
6. We then iterate through the first n positions (from 0 to n-1) and calculate the absolute difference between
    the position of the element in pos and its expected position (n + i + 1). We add this difference to ans.
7. Finally, we print the value of ans for each test case.
*/


// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// int main() {
// 	// your code goes here
// 	int t;
// 	 cin>>t;
// 	 while(t--){
// 	     int n;
// 	     cin>>n;
// 	     ll N = n*2;
// 	     vector<ll> arr(N);
// 	     for(int i = 0;i < N; i++ ){
// 	         cin>>arr[i];
// 	     }
// 	     int count = 0;
// 	     int result = 0;
// 	     for(int i = 0; i<N; i++){
// 	         if(arr[i] > n){
// 	             count++;
// 	         }else{
// 	             result = result+count;
// 	         }
// 	     }
// 	  cout<<result<<"\n";
// 	 }
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(2*n);
        for(int i = 0; i < 2*n; i++) cin >> arr[i];
        
        vector<int> pos;
        for(int i = 0; i < 2*n; i++)
            if(arr[i] > n) pos.push_back(i + 1);
        
        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += abs(pos[i] - (n + i + 1));
        
        cout << ans << "\n";
    }
}