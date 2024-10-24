class Solution {
public:

    int solve(vector<int>& nums, int target, int index, vector<vector<int>>& dp){
        if(target == 0){
            return 1;
        }
        if(index >= nums.size() || target < 0){
            return 0;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }

        int exclude = solve(nums, target, index+1, dp);
        int include = solve(nums, target-nums[index], index+1, dp);
        dp[index][target] = exclude || include;
        return dp[index][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int target = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        if(sum%2 != 0){
            return false;
        }else{
            int ans = solve(nums, target, 0, dp);
            if(ans == 1){
                return true;
            }else{
                return false;
            }
        }
    }
};