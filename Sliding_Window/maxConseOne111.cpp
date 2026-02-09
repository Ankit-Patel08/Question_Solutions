// leetCode   1004. Max Consecutive Ones III

// used the concept of sliding window and two pointer approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
    int zeroCount = 0;
    int left = 0;
    int maxlen = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] == 0) zeroCount++;

        while(zeroCount>k){
            if(nums[left] == 0) {
                zeroCount--;
                }
            left++;
        }
        maxlen = max(maxlen, i-left+1);
    }
    return maxlen;
    }
};
