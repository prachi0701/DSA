class Solution {
public:

    void solve(vector<int>& candidates, int target, int index, vector<vector<int>>& ans, vector<int> temp){
        // if(index >= candidates.size()){
        //     if(target == 0){
        //         sort(temp.begin(), temp.end());
        //         ans.insert(temp);
        //     }
        //     return;
        // }
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(i != index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i+1, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, ans, temp);
        return ans;;
    }
};