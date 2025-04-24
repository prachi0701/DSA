class Solution {
public:

    void solve(vector<int>& candidates, int target, int index, vector<vector<int>> &ans, vector<int> temp){
        if(index >= candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            solve(candidates, target - candidates[index], index, ans, temp);
            temp.pop_back();
        }

        solve(candidates, target, index+1, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, ans, temp);
        return ans;
    }
};