
/*
55. Jump Game 
Approach -> Greedy
Time Complexity -> O(n)
 intution -> We keep track of the maximum index we can reach at each step.
  If we encounter an index that is beyond our maximum reachable index, 
  it means we cannot proceed further.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
           if(i > maxi){
            return false;
           }
           maxi = max(maxi, i+nums[i]);
        }
       return true;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }

    Solution sol;
    bool result = sol.canJump(nums);

    if(result){
        cout<<"You can jump to the end of the array."<<endl;
    } else {
        cout<<"You cannot jump to the end of the array."<<endl;
    }

    return 0;
}