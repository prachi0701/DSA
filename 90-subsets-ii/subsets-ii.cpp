class Solution {
public:

    void solve(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int>& temp){
        ans.push_back(temp);
        for(int i=index; i<nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            solve(nums, i+1, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans, temp);
        return ans;
    }
};