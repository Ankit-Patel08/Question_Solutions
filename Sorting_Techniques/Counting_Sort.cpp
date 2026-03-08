/*
# Counting Sort (C++ Implementation)

## 📌 Overview

Counting Sort is a **non-comparison based sorting algorithm** used for sorting integers within a **limited range**.
Instead of comparing elements like most sorting algorithms, Counting Sort counts the number of occurrences of each value and uses this information to place elements in their correct positions.

Because it avoids comparisons, Counting Sort can achieve **linear time complexity** under the right conditions.

Counting Sort works best when the **range of input values is not significantly larger than the number of elements**.

---

## 🎯 Why Counting Sort is Used

Traditional sorting algorithms such as **Merge Sort, Quick Sort, and Heap Sort** rely on comparisons between elements.

Counting Sort takes a different approach:

* It **counts how many times each value appears**
* It calculates the **position of each value in the sorted array**
* It then places the elements directly into their correct positions

This eliminates the need for repeated comparisons.

---

## ⚙️ How Counting Sort Works

Steps:

1. Find the **maximum value** in the array.
2. Create a **count array** of size `max + 1`.
3. Store the frequency of each element in the count array.
4. Convert the count array into a **prefix sum array** to determine positions.
5. Build the **output array** by placing elements in their correct sorted position.
6. Copy the sorted output back to the original array.

---

## 🧠 Example

Input Array:

```text
[4, 2, 2, 8, 3, 3, 1]
```

Step 1 — Count frequency of elements:

```text
Value : 0 1 2 3 4 5 6 7 8
Count : 0 1 2 2 1 0 0 0 1
```

Step 2 — Convert to cumulative counts:

```text
Count : 0 1 3 5 6 6 6 6 7
```

Step 3 — Build sorted output:

```text
[1, 2, 2, 3, 3, 4, 8]
```

---

## 💻 C++ Implementation

```cpp
*/
#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>&arr){
	int maxi = arr[0];
	int n = arr.size();
	for(int i = 1; i<n; i++){           // Find the maximum value in the array to determine the size of the count array
		maxi = max(maxi, arr[i]);
	}
	vector<int>count(maxi+1,0);         // Create a count array to store the frequency of each value, initialized to 0
	vector<int> ans(n);
	
	for(int i = 0; i<n; i++){             // Count the frequency of each element in the input array and store it in the count array
		count[arr[i]]++;
	}

	for(int i = 1; i<=maxi; i++){               // Convert the count array into a prefix sum array to determine the position of each element in the sorted output
		count[i] = count[i-1]+count[i];
	}

	for(int i = n-1; i>=0; i--){             // Build the output array by placing elements in their correct sorted position based on the count array, iterating from the end to maintain stability
		ans[count[arr[i]]-1] = arr[i];       // Place the element at its correct position in the output array and decrease the count for that element
		count[arr[i]]--;
	}
	for(int i = 0; i<n; i++){               // Copy the sorted output back to the original array
		arr[i] = ans[i];
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	countingSort(arr);
	for(int i = 0; i<n;i++){
			cout<<arr[i]<<" ";
	}
	return 0;
}
/*
```

---

## ⏱ Time Complexity

| Case         | Complexity |
| ------------ | ---------- |
| Best Case    | O(n + k)   |
| Average Case | O(n + k)   |
| Worst Case   | O(n + k)   |

Where:

* `n` = number of elements
* `k` = range of input values

---

## 📦 Space Complexity

```text
O(n + k)
```

Counting Sort requires extra memory for:

* The **count array**
* The **output array**

---

## 👍 Advantages

* Very fast for **small integer ranges**
* Linear time complexity
* Does not rely on comparisons
* Stable sorting algorithm
* Works well as a **subroutine in other algorithms**

---

## 👎 Disadvantages

* Not suitable for **large value ranges**
* Requires **extra memory**
* Only works with **integers or discrete values**

---

## 📍 When to Use Counting Sort

Counting Sort is useful when:

* The input elements are **integers**
* The **range of values is small**
* The number of elements is **large**
* A **stable sorting algorithm** is required

Common use cases include:

* Sorting exam scores
* Sorting age groups
* Sorting small integer datasets
* As part of **Radix Sort**

---

## 🔑 Key Idea

Instead of comparing elements with each other, Counting Sort determines the **final position of each element by counting how many elements are smaller than it**.

This allows the algorithm to place elements directly into their sorted positions.

---

*/