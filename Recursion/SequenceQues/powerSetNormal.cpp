#include <bits/stdc++.h>
using namespace std;

class Solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        int n = nums.size();
        vector<vector<int>>ans;
       for(int i = 0; i<(1<<n); i++){
        vector<int> sub;
        for(int j = 0; j<n; j++){
            if(i&(1<<j)){
               sub.push_back(nums[j]);
            }
        }
        ans.push_back(sub);
       }
       return ans;
    }
};

int main(){
    Solution obj;
    vector<int>nums = {1,2,3};
    vector<vector<int>>ans = obj.powerSet(nums);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}



/*
# 📌 Power Set (Subsets) — Bitmasking Approach Notes

## 🧠 Core Concept

* The problem is based on **Bit Manipulation (Bitmasking)**.
* Every subset can be represented using a **binary number**.

---

## 💡 Key Idea

* For an array of size `n`, total subsets = **2ⁿ**
* Numbers from `0 → (2ⁿ - 1)` represent all subsets.
* Each number’s binary form tells whether to include an element or not.

---

## 🔢 Representation

Example:

```
nums = {1, 2, 3}
n = 3
```

| Decimal (i) | Binary | Subset  |
| ----------- | ------ | ------- |
| 0           | 000    | {}      |
| 1           | 001    | {1}     |
| 2           | 010    | {2}     |
| 3           | 011    | {1,2}   |
| 4           | 100    | {3}     |
| 5           | 101    | {1,3}   |
| 6           | 110    | {2,3}   |
| 7           | 111    | {1,2,3} |

---

## ⚙️ Logic Used in Code

### Loop over all subsets

```
for(int i = 0; i < (1<<n); i++)
```

* `(1 << n)` = `2ⁿ`
* Each `i` represents one subset

---

### Check each bit

```
if(i & (1<<j))
```

* If j-th bit is **ON** → include element  means if the bit is 1 then the element is included
* If j-th bit is **OFF** → skip element

---

## 🧠 Mental Model

* Each number `i` is a **decision pattern**
* For each element:

  * `0 → Not take`
  * `1 → Take`

👉 Binary = automatic decision maker

---

## 🔄 Alternative Approach (Recursion)    

### Idea:

* For each element:

  * Take it
  * Don't take it

### Recursion Tree Example:

```
          []
        /    \
     [1]      []
    /  \     /  \
 [1,2] [1] [2]  []
```

---

## 🔁 Relation Between Approaches

| Approach   | Thinking                           |
| ---------- | ---------------------------------- |
| Recursion  | Explicit choices (take / not take) |
| Bitmasking | Binary represents choices          |

👉 Both solve the same problem in different ways

---

## 🚀 When to Use Bitmasking

* When `n` is small (≤ 20)
* When all subsets are required
* When no extra constraints are present

---

## ⚠️ When to Prefer Recursion

* When constraints are involved
* When pruning is needed
* When conditions depend on previous choices

---

## 📌 Key Takeaway

```
If problem involves choices:
→ Each element has 2 options
→ Total = 2ⁿ
→ Use Recursion OR Bitmasking
```

---

## 🧩 Time & Space Complexity

* Time Complexity: **O(n × 2ⁿ)**
* Space Complexity: **O(2ⁿ)** (for storing subsets)

---

## 🏁 Summary

* Bitmasking converts decision-making into binary form
* Each bit represents inclusion/exclusion
* Faster and cleaner alternative to recursion for subset problems

---

🔥 **Golden Rule:**

> Subsets / Subsequences / Combinations → Think in terms of **2 choices → 2ⁿ → Bitmask or Recursion**

*/