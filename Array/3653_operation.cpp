#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        // Process each query
        for (auto &q : queries) {
            int li = q[0];
            int ri = q[1];
            int ki = q[2];
            int vi = q[3];

            // Apply multiplication on indices: li, li+ki, li+2ki, ...
            for (int idx = li; idx <= ri; idx += ki) {
                nums[idx] = (1LL * nums[idx] * vi) % MOD;
            }
        }

        // Compute XOR of final array
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example Input
    vector<int> nums = {2, 3, 1, 5, 4};
    vector<vector<int>> queries = {
        {1, 4, 2, 3},
        {0, 2, 1, 2}
    };

    int result = sol.xorAfterQueries(nums, queries);

    cout << "Final XOR: " << result << endl;

    return 0;
}
