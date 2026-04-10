class Solution {
public:
    void combi(vector<int>&nums, int idx, vector<vector<int>>&ans, vector<int>&curr, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            if(nums[i] > target) break;
            if( i > idx && nums[i] == nums[i-1]) continue;   // to avoid duplicates
            if(target > 0){
            curr.push_back(nums[i]);
            combi(nums, i+1, ans, curr, target-nums[i]);  // to avoid duplicates of elements
            curr.pop_back();
           }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        combi(candidates,0,ans,curr,target);
        return ans;
    }
};