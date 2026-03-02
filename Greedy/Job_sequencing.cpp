/*
===========================================
     JOB SEQUENCING WITH DEADLINES
===========================================

Problem:
Given:
- n jobs
- Each job has:
      id
      deadline
      profit
- Each job takes exactly 1 unit of time
- Only one job can be done at a time

Goal:
Maximize total profit by scheduling jobs
before their deadlines.

-------------------------------------------
GREEDY IDEA:
-------------------------------------------
Always schedule the job with the highest
profit first.

Why?
If we miss a high-profit job,
we lose more money.

-------------------------------------------
APPROACH:
-------------------------------------------

1. Store all jobs in a structure:
      {id, deadline, profit}

2. Sort jobs in descending order of profit.

3. Find maximum deadline:
      This tells how many time slots we need.

4. Create a slot array of size:
      maxDeadline + 1
   Initialize all slots as empty.

5. For each job (in sorted order):
      Try to place it in the latest
      available slot before its deadline.

      For j = deadline → 1:
          If slot[j] is empty:
              Assign job to slot[j]
              Add profit
              Break

6. Print scheduled jobs and total profit.

-------------------------------------------
WHY WE PLACE JOB AT LATEST SLOT?
-------------------------------------------
If we place a job earlier,
it may block another job
with an earlier deadline.

So we place each job as late as possible.

-------------------------------------------
TIME COMPLEXITY:
-------------------------------------------
Sorting: O(n log n)
Slot checking (worst case): O(n^2)

Overall: O(n^2)

(Optimized version using DSU → O(n log n))

-------------------------------------------
SPACE COMPLEXITY:
-------------------------------------------
O(n)

-------------------------------------------
When to Use:
-------------------------------------------
- Scheduling with deadlines
- Profit maximization problems
- Greedy optimization problems

===========================================
*/

#include<bits/stdc++.h>
using namespace std;

struct activity{
    char id;
    int deadline;
    int profit;
};

int main(){
    int n;
    cin >> n;

    vector<activity> all(n);

    // Input jobs
    for(int i = 0; i < n; i++){
        cin >> all[i].id >> all[i].deadline >> all[i].profit;
    }

    // Step 1: Sort by profit (descending)
    sort(all.begin(), all.end(), [](activity a, activity b){
        return a.profit > b.profit;
    });

    // Step 2: Find maximum deadline
    int maxdeadl = 0;
    for(int i = 0; i < n; i++){
        maxdeadl = max(maxdeadl, all[i].deadline);
    }

    // Step 3: Create slot array
    vector<char> emptyslots(maxdeadl + 1, '\0');

    int totalProfit = 0;

    // Step 4: Assign jobs
    for(int i = 0; i < n; i++){
        for(int j = all[i].deadline; j > 0; j--){
            if(emptyslots[j] == '\0'){
                emptyslots[j] = all[i].id;
                totalProfit += all[i].profit;
                break;
            }
        }
    }

    // Print scheduled jobs
    for(int i = 1; i <= maxdeadl; i++){
        if(emptyslots[i] != '\0'){
            cout << emptyslots[i] << " ";
        }
    }

    cout << endl;
    cout << totalProfit << endl;

    return 0;
}