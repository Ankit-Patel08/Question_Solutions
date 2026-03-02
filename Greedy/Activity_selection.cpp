/*
===========================================
        ACTIVITY SELECTION PROBLEM
===========================================

Problem:
Given:
- n activities
- Each activity has:
      start time
      finish time

Constraint:
Only one activity can be performed at a time.

Goal:
Select the maximum number of non-overlapping activities.

-------------------------------------------
GREEDY IDEA:
-------------------------------------------
Always select the activity that finishes earliest.

Why?
Because finishing early leaves maximum time
for other activities.

This follows the GREEDY CHOICE PROPERTY.

-------------------------------------------
APPROACH:
-------------------------------------------

1. Store activities as pairs:
      (start, finish)

2. Sort activities in ascending order
   of finish time.

3. Select the first activity
   (it has earliest finish time).

4. For remaining activities:
      If start >= last selected finish:
            Select it
            Update last finish time

5. Count total selected activities.

-------------------------------------------
WHY GREEDY WORKS HERE:
-------------------------------------------
Choosing the earliest finishing activity
always leaves more room for future activities.

If we pick a later finishing activity first,
we may block multiple smaller activities.

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
- Scheduling problems
- Interval selection problems
- Meeting room type problems

===========================================
*/

#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort by finish time
bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> activities;

    // Input start and finish times
    for(int i = 0; i < n; i++){
        int start, finish;
        cin >> start >> finish;
        activities.push_back({start, finish});
    }

    // Step 1: Sort by finish time
    sort(activities.begin(), activities.end(), compare);

    // Step 2: Select first activity
    int count = 1;
    int lastFinish = activities[0].second;

    // Step 3: Check remaining activities
    for(int i = 1; i < n; i++){
        if(activities[i].first >= lastFinish){
            count++;
            lastFinish = activities[i].second;
        }
    }

    cout << count << endl;

    return 0;
}