/*
# Radix Sort (C++ Implementation)

## 📌 Overview

Radix Sort is a **non-comparison based sorting algorithm** that sorts numbers by processing individual digits.
Instead of comparing elements directly, Radix Sort sorts numbers **digit by digit**, starting from the **least significant digit (LSD)** to the **most significant digit (MSD)**.

Radix Sort commonly uses **Counting Sort as a subroutine** to sort numbers based on each digit.

Because it avoids element comparisons, Radix Sort can achieve **linear time complexity for certain types of input data**.

---

## 🎯 Why Radix Sort is Used

Traditional sorting algorithms like **Quick Sort, Merge Sort, and Heap Sort** compare elements with each other.

Radix Sort works differently:

* It processes numbers **digit by digit**
* It sorts numbers based on **place value (units, tens, hundreds, etc.)**
* It uses **Counting Sort internally to maintain stability**

This approach can make sorting faster when dealing with **large datasets of integers with limited digit length**.

---

## ⚙️ How Radix Sort Works

Steps:

1. Find the **maximum number** in the array.
2. Start sorting numbers based on the **least significant digit (units place)**.
3. Use **Counting Sort** to sort numbers based on that digit.
4. Move to the **next digit place (tens, hundreds, etc.)**.
5. Repeat until the **largest digit place of the maximum number** is processed.

---

## 🧠 Example

Input Array:

```text
[170, 45, 75, 90, 802, 24, 2, 66]
```

Step 1 — Sort by **units digit**

```text
[170, 90, 802, 2, 24, 45, 75, 66]
```

Step 2 — Sort by **tens digit**

```text
[802, 2, 24, 45, 66, 170, 75, 90]
```

Step 3 — Sort by **hundreds digit**

```text
[2, 24, 45, 66, 75, 90, 170, 802]
```

Final Sorted Array:

```text
[2, 24, 45, 66, 75, 90, 170, 802]
```

---

## 💻 C++ Implementation

```cpp
*/

#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);       // Count array to store count of occurrences of digits (0-9)

    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;          // Count occurrences of each digit in the exp place

    for(int i = 1; i < 10; i++)         // Update count[i] to contain the cumulative count of digits up to i
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;           // Get the digit in the exp place
        output[count[digit] - 1] = arr[i];           // Place the element in the output array based on the cumulative count and decrease the count for that digit
        count[digit]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr)
{
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());

    for(int exp = 1; maxi / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr);

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++)
            cout << arr[i] << " ";

    return 0;
}

/*

```

---

## ⏱ Time Complexity

| Case         | Complexity     |
| ------------ | -------------- |
| Best Case    | O(d × (n + k)) |
| Average Case | O(d × (n + k)) |
| Worst Case   | O(d × (n + k)) |

Where:

* `n` = number of elements
* `d` = number of digits in the largest number
* `k` = range of digits (0–9)

---

## 📦 Space Complexity

```text
O(n + k)
```

Radix Sort requires additional memory for the **count array and output array**.

---

## 👍 Advantages

* Faster than many comparison-based algorithms for **large datasets**
* Linear time complexity for certain inputs
* Works very well when numbers have **similar digit lengths**
* Stable sorting algorithm
* Efficient for sorting **large integer datasets**

---

## 👎 Disadvantages

* Only works well with **integers or fixed-length data**
* Requires **extra memory**
* Performance decreases if numbers have **very large digit lengths**

---

## 📍 When to Use Radix Sort

Radix Sort is useful when:

* Sorting **large lists of integers**
* The **number of digits is limited**
* Stable sorting is required
* Data values fall within a **known numeric range**

Common applications include:

* Sorting large datasets of numbers
* Sorting phone numbers
* Sorting IDs
* Used internally in some database and indexing systems

---

## 🔑 Key Idea

Radix Sort avoids comparing numbers directly.
Instead, it **groups numbers based on their digits and sorts them step by step**, starting from the least significant digit to the most significant digit.

This allows the algorithm to achieve near **linear time performance** for suitable datasets.

*/