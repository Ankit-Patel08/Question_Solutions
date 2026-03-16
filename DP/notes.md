                ### DYNAMIC PROGRAMMING
-> Dynamic programming is a method for solving complex problems by breaking them down into simpler subproblems, storing the results of those subproblems to avoid redundant work. It is often used in optimization problems where the solution can be expressed as a combination of solutions to smaller instances of the same problem.

-> The key idea behind dynamic programming is to use a table (often an array or a matrix) to store the results of subproblems. This allows the algorithm to avoid redundant calculations and significantly reduce the time complexity of the solution.

-> Dynamic programming can be applied to problems that exhibit two main properties: optimal substructure and overlapping subproblems. 
   Optimal substructure means that the optimal solution to a problem can be constructed from optimal solutions to its subproblems.
   Overlapping subproblems means that the same subproblems are solved multiple times during the computation.

-> There are two main approaches to dynamic programming: top-down (memoization) and bottom-up (tabulation).
   - Top-down (memoization) involves writing the recursive solution and storing the results of subproblems in a cache (usually a dictionary or an array) to avoid redundant calculations.
   - Bottom-up (tabulation) involves filling a table iteratively based on the solutions to smaller subproblems, starting from the base cases and building up to the final solution.

 
 let's see an example of a classic dynamic programming problem: the Fibonacci sequence.

The Fibonacci sequence is defined as follows:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1

### Top-Down Approach (Memoization)
```c++
#include <iostream>
#include <vector>   
using namespace std;
void memoization() {
    vector<long long> memo; // Create a vector to store results
    memo.resize(100, -1); // Initialize with -1 to indicate uncomputed values
  long long fibonacci(int n) {
    if (n <= 1) return n; // Base cases
    if (memo[n] != -1) return memo[n]; // Check if result is already computed
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2); // Compute and store the result
    return memo[n];
}
}
 
```

### Bottom-Up Approach (Tabulation)


```c++
#include <iostream>
using namespace std;
long long fibonacci(int n) {
    if (n <= 1) return n; // Base cases
    long long dp[n + 1]; // Create a table to store results
    dp[0] = 0; // F(0)                                  // by this we are filling the table iteratively
    dp[1] = 1; // F(1)
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Fill the table iteratively
    }
    return dp[n];
}

with small optimization we can reduce the space complexity to O(1) by only keeping track of the last two computed values instead of the entire table.

```c++
#include <iostream>
using namespace std;
long long fibonacci(int n) {
    if (n <= 1) return n; // Base cases
    long long a = 0, b = 1; // Initialize the first two Fibonacci numbers
    for (int i = 2; i <= n; i++) {
        long long temp = a + b; // Compute the next Fibonacci number
        a = b; // Update a to the previous Fibonacci number
        b = temp; // Update b to the current Fibonacci number
    }
    return b; // Return the nth Fibonacci number
}
```