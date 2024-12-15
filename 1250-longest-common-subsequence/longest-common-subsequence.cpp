class Solution {
public:

    int solve(string text1, string text2, int i, int j, vector<vector<int>>& dp){
        if(i == text1.length() || j == text2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            dp[i][j] = 1 + solve(text1, text2, i+1, j+1, dp);
        }
        else{
            dp[i][j] = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }
        return dp[i][j];
    }

    int solveTab(string text1, string text2){
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }

    int solveSO(string text1, string text2){
        int n = text1.length();
        int m = text2.length();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    curr[j] = 1 + next[j+1];
                }
                else{
                    curr[j] = max(next[j], curr[j+1]);
                }
            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.length();
        // int m = text2.length();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return LCS(text1, text2, 0, 0, dp);

        // return solveTab(text1, text2);

        return solveSO(text1, text2);
    }
};