/*
# Shell Sort (C++ Implementation)

## 📌 Overview

Shell Sort is an **in-place comparison-based sorting algorithm** that improves upon **Insertion Sort**.
It works by comparing elements that are **far apart first**, then gradually reducing the gap between elements to be compared.

By allowing elements to move long distances early in the sorting process, Shell Sort significantly reduces the number of shifts required compared to standard insertion sort.

The algorithm was introduced by **Donald Shell in 1959**.

---

## 🎯 Why Shell Sort is Used

Insertion sort works well when the array is almost sorted, but it performs poorly when elements are far away from their correct positions.

Shell Sort solves this problem by:

* First moving elements **long distances** using large gaps
* Gradually reducing the gap
* Finishing with **insertion sort when the array is nearly sorted**

This approach reduces the total number of swaps and comparisons.

---

## ⚙️ How Shell Sort Works

1. Start with a large **gap value** (usually `n/2`).
2. Compare elements that are `gap` positions apart.
3. Perform **insertion sort on elements separated by the gap**.
4. Reduce the gap (`gap = gap / 2`).
5. Repeat until the gap becomes **1**.

When the gap becomes **1**, the algorithm behaves like insertion sort, but the array is already mostly sorted, making it very efficient.

---

## 🧠 Example

Initial Array:

```
[12, 34, 54, 2, 3]
```

Step 1 — Gap = n/2 = 5/2 = 2

Compare elements 2 positions apart:

```
(12, 54)
(34, 2)
(54, 3)
```

Array becomes:

```
[3, 2, 12, 34, 54]
```

Step 2 — Gap = 1

Now perform insertion sort:

Final sorted array:

```
[2, 3, 12, 34, 54]
```

---

## 💻 C++ Implementation

```cpp*/

#include<bits/stdc++.h>
using namespace std;

void shellSort(vector<int> &arr){
	int n = arr.size();
	for(int gap = n/2; gap>=1; gap/2){
		for(int j = gap; j < n; j++){
			for( int i = j - gap; i >= 0; i-gap){
				if(arr[i+gap] > arr[i]){
					break;
				}else{
					swap(arr[i+gap],arr[i]);
				}
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i = 0;i<n; i++){
		cin>>arr[i];
	}
	shellSort(arr);
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

/*

## ⏱ Time Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | O(n log n)      |
| Average Case | ~O(n^1.3)       |
| Worst Case   | O(n²)           |

The complexity depends on the **gap sequence used**.

---

## 📦 Space Complexity

```
O(1)
```

Shell Sort is an **in-place sorting algorithm**, meaning it does not require extra memory.

---

## 👍 Advantages

* Faster than **Bubble Sort** and **Insertion Sort**
* Efficient for **medium-sized datasets**
* Requires **very little additional memory**
* Simple to implement
* Reduces large element shifts early

---

## 👎 Disadvantages

* Slower than advanced algorithms like **Merge Sort**, **Quick Sort**, and **Heap Sort** for very large datasets
* Performance depends heavily on the **gap sequence**
* Not a **stable sorting algorithm**

---

## 📍 When to Use Shell Sort

Shell Sort is useful when:

* The dataset size is **small to medium**
* Memory usage must be **minimal**
* The array is **partially sorted**
* You want something faster than insertion sort but simpler than more complex algorithms

---

## 🔑 Key Idea

Instead of moving elements **one position at a time (like insertion sort)**, Shell Sort moves elements **multiple positions at once using gaps**, which significantly reduces the number of swaps required.

---

## 🧠 Conclusion
Shell Sort is a powerful sorting algorithm that offers a good balance between simplicity and efficiency for certain types of datasets. It is particularly effective when the input array is already partially sorted, making it a great choice for many real-world applications.
*/