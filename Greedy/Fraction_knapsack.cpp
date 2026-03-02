/*
===========================================
        FRACTIONAL KNAPSACK PROBLEM
===========================================

Problem:
Given:
- n items
- Each item has:
      value
      weight
- A knapsack with capacity W

Goal:
Maximize total value inside the knapsack.

IMPORTANT:
We are ALLOWED to take fractions of items.

-------------------------------------------
GREEDY IDEA:
-------------------------------------------
Always pick the item with the highest
value per unit weight (value/weight ratio).

Because:
Taking more value per unit weight
maximizes total profit.

-------------------------------------------
APPROACH:
-------------------------------------------

1. Store items as:
      (value, weight)

2. Sort items in descending order of:
      value/weight ratio

3. Initialize:
      ans = 0
      remaining capacity = W

4. Traverse sorted items:

   For each item:
      If remaining capacity >= weight:
          Take whole item
          Add full value to ans
          Reduce capacity

      Else:
          Take fraction of item
          Add (value/weight) * remaining capacity
          Break loop

5. Print answer with 6 decimal precision

-------------------------------------------
WHY GREEDY WORKS HERE:
-------------------------------------------
Because fractional selection is allowed.

Taking highest ratio first always gives
maximum possible gain.

NOTE:
Greedy DOES NOT work for 0/1 knapsack,
but works for Fractional Knapsack.

-------------------------------------------
TIME COMPLEXITY:
-------------------------------------------
Sorting: O(n log n)
Traversal: O(n)

Overall: O(n log n)

-------------------------------------------
SPACE COMPLEXITY:
-------------------------------------------
O(n)

-------------------------------------------
When to Use:
-------------------------------------------
- Items can be divided
- Need maximum profit
- Classic greedy optimization problem

===========================================
*/

#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	double w;
	cin>>n>>w;
	vector<pair<double,double>>arr;

	for(int i = 0 ;i<n; i++){
		double value , weight;
		cin>>value>>weight;
		arr.push_back({value, weight});
	}
              // Sort items by value/weight ratio in descending order
	sort(arr.begin(), arr.end(),[](pair<double,double>a, pair<double,double>b){ 
		return (a.first/a.second) > (b.first/b.second);
	});

	double ans = 0.0;
	for(int i = 0; i<n; i++){   // Traverse sorted items
        if(w <= 0) break;       // If knapsack is full, stop
		if(w >= arr[i].second){   // If we can take whole item
			ans = ans+arr[i].first;
			w = w-arr[i].second;
		}else{                              // Take fraction of item
			ans = ans+ (arr[i].first/arr[i].second)*w;
			break;
		}
	}
	cout<< fixed<<setprecision(6) << ans <<endl;    // Print answer with 6 decimal places
	return 0;
}