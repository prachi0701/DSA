class Solution {
public:
    // n == slices to eat which is k/3
    // int solve(int index, int endIndex, vector<int>& slices, int n){
    //     if(n == 0 || index > endIndex){
    //         return 0;
    //     }

    //     int include = slices[index] + solve(index+2, endIndex, slices, n-1);
    //     int exclude = 0 + solve(index+1, endIndex, slices, n);
    //     return max(include, exclude);
    // }

    int solveMem(int index, int endIndex, vector<int>& slices, int n,  vector<vector<int>>& dp){
        if(n == 0 || index > endIndex){
            return 0;
        }
        if(dp[index][n] != -1){
            return dp[index][n];
        }

        int include = slices[index] + solveMem(index+2, endIndex, slices, n-1, dp);
        int exclude = 0 + solveMem(index+1, endIndex, slices, n, dp);
        dp[index][n] = max(include, exclude);
        return dp[index][n];
    }

    int solveTab(vector<int>& slices){
        int k = slices.size();
        vector<vector<int>> dp1(k+2, vector<int>(k+2, 0));
        vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));

        for(int index = k-2; index >= 0; index--){
            for(int n = 1; n <= k/3; n++){
                int include = slices[index] + dp1[index+2][n-1];
                int exclude = dp1[index+1][n];
                dp1[index][n] = max(include, exclude);
            }
        }
        int case1 = dp1[0][k/3];

        for(int index = k-1; index >= 1; index--){
            for(int n = 1; n <= k/3; n++){
                int include = slices[index] + dp2[index+2][n-1];
                int exclude = dp2[index+1][n];
                dp2[index][n] = max(include, exclude);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // vector<vector<int>> dp1(k, vector<int>(k/3+1, -1));
        // vector<vector<int>> dp2(k, vector<int>(k/3+1, -1));
        // int case1 = solveMem(0, k-2, slices, k/3, dp1);
        // int case2 = solveMem(1, k-1, slices, k/3, dp2);
        // int ans = max(case1, case2);
        // return ans;

        return solveTab(slices);
    }
};