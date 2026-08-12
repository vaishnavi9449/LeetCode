class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int i) {
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==candidates.size()||target<0){
            return;
        }
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i);
            temp.pop_back();
        }
        solve(candidates,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,0);
        return ans;
    }
};