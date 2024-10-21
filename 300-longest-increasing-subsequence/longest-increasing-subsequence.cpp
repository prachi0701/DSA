class Solution {
public:

    int solve(vector<int>& nums, int index, int prev, vector<vector<int>>& dp){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index][prev+1] != -1){
            return dp[index][prev+1];
        }

        int include = 0;
        if(prev == -1 || nums[index] > nums[prev]){
            include = 1 + solve(nums, index+1, index, dp);
        }
        int exclude = solve(nums, index+1, prev, dp);

        dp[index][prev+1] = max(exclude, include);
        return dp[index][prev+1];
    }

    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int index = n-1; index>=0; index--){
            for(int prev = index-1; prev >= -1; prev--){
                int exclude = dp[index+1][prev+1];
                int include = 0;
                if(prev == -1 || nums[index] > nums[prev]){
                    include = 1 + dp[index+1][index+1];
                }
                dp[index][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // int ans = solve(nums, 0, -1, dp);
        // return ans;

        int ans = solveTab(nums);
        return ans;
    }
};