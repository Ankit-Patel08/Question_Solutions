// 414. Third Maximum Number   

// have solved this in O(n) time complexity and O(1) space complexity
// by taking 3 pointers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        long long first = LLONG_MIN;
        long long  second = LLONG_MIN;
        long long  third = LLONG_MIN;
        for( int x: nums){
            if(x > first){
                third = second;
                second = first;
                first = x;
            }else if(x > second && x < first){
                third = second;
                 second = x;
            }else if( x > third && x < second){
                third = x;
            }
        }
        if(third == LLONG_MIN){
            return first;
        }else{
            return third;
        }
    }
};