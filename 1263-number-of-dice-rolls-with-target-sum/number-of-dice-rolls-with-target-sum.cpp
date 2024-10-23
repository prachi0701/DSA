#define MOD 1000000007

class Solution {
public:

    int solve(int n, int k, int target, vector<vector<int>>& dp){
        if(target < 0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        if(n == 0 && target == 0){
            return 1;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = (ans + solve(n-1, k, target-i, dp))%MOD;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        int ans = solve(n, k, target, dp);
        return ans;
    }
};