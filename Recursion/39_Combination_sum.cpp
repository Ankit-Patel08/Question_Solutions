class Solution {
public:
    void combi(vector<int>&candidates, vector<int> & curr, int idx, int target, vector<vector<int>>&ans){

            if(target == 0){
            ans.push_back(curr);
            return;
            }
        
        for(int i = idx; i< candidates.size(); i++){
            if(target > 0){
            curr.push_back(candidates[i]);
            combi(candidates,curr,i,target-candidates[i],ans);
            curr.pop_back();
        }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        combi(candidates,curr,0,target,ans);
        return ans;
    }
};