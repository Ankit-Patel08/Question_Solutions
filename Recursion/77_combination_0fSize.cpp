class Solution {
public:
    void combi(vector<int>&nums, vector<int>&curr, int idx,int k,vector<vector<int>>&ans){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i<nums.size(); i++){
            curr.push_back(nums[i]);
            combi(nums, curr, i+1,k,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            arr[i] = i+1;
        }
        vector<vector<int>>ans;
        vector<int>curr;
        combi(arr, curr, 0,k,ans);
        return ans;
    }
};