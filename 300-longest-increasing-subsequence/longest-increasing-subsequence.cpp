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

    int solveSpaceOpt(vector<int>& nums){
        int n = nums.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int index = n-1; index>=0; index--){
            for(int prev = index-1; prev >= -1; prev--){
                int exclude = next[prev+1];
                int include = 0;
                if(prev == -1 || nums[index] > nums[prev]){
                    include = 1 + next[index+1];
                }
                curr[prev+1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int solveBinarySearch(vector<int>& nums){
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                // just bada element find karenge
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // int ans = solve(nums, 0, -1, dp);
        // return ans;

        // int ans = solveTab(nums);
        // return ans;

        // return solveSpaceOpt(nums);

        return solveBinarySearch(nums);
    }
};