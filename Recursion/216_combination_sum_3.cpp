class Solution {
public:
    void combi(vector<int>&nums, int idx, vector<int>& curr, int target,int k, vector<vector<int>>&ans) {
        if(curr.size() == k  && target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            if(nums[i] > target) break;
            if(target > 0){
                curr.push_back(nums[i]);
                combi(nums,i+1,curr,target-nums[i],k,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int>curr;
        vector<vector<int>>ans;
        combi(arr,0,curr,n,k,ans);
        return ans;
    }
};