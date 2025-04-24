class Solution {
public:

    void solve(vector<int>& nums, int index, set<vector<int>> &result, vector<int> temp){
        if(index >= nums.size()){
            sort(temp.begin(), temp.end());
            result.insert(temp);
            return;
        }
        solve(nums, index+1, result, temp);    //exclude
        temp.push_back(nums[index]);
        solve(nums, index+1, result, temp);    //include
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> temp;
        solve(nums, 0, result, temp);
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};