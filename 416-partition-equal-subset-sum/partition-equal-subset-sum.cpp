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


    int solveTab(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=target; j++){
                int exclude = dp[i+1][j];
                int include = 0;
                if(j-nums[i] >= 0){
                    include = dp[i+1][j-nums[i]];
                }
                dp[i][j] = exclude || include;
            }
        }
        return dp[0][target];
    }

    int solveSpaceOpt(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        next[0] = 1;

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=target; j++){
                int exclude = next[j];
                int include = 0;
                if(j-nums[i] >= 0){
                    include = next[j-nums[i]];
                }
                curr[j] = exclude || include;
            }
            next = curr;
        }
        return curr[target];
    }


    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int target = sum/2;

        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        if(sum%2 != 0){
            return false;
        }else{
            // int ans = solve(nums, target, 0, dp);

            // int ans = solveTab(nums, target);

            int ans = solveSpaceOpt(nums, target);

            if(ans == 1){
                return true;
            }else{
                return false;
            }
        }
    }
};