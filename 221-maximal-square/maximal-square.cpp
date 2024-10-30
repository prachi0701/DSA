class Solution {
public:

    int solve(vector<vector<char>>& matrix, int &maxi, int i, int j){
        if( i>= matrix.size() || j>=matrix[0].size()){
            return 0;
        }

        int right = solve(matrix, maxi, i, j+1);
        int digonal = solve(matrix, maxi, i+1, j+1);
        int down = solve(matrix, maxi, i+1, j);

        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(digonal, down));
            maxi = max(maxi, ans);
            return ans;
        }else{
            return 0;
        }
    }

    int solveMem(vector<vector<char>>& matrix, int &maxi, int i, int j, vector<vector<int>>& dp){
        if( i>= matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solveMem(matrix, maxi, i, j+1, dp);
        int digonal = solveMem(matrix, maxi, i+1, j+1, dp);
        int down = solveMem(matrix, maxi, i+1, j, dp);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(digonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }else{
            return dp[i][j] = 0;
        }
    }

    int solveTab(vector<vector<char>>& matrix, int& maxi){
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                int right = dp[i][j+1];
                int dignol = dp[i+1][j+1];
                int down = dp[i+1][j];
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(right, min(dignol, down));
                    maxi = max(maxi, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }

    int solveSO(vector<vector<char>>& matrix, int& maxi){
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> curr(col+1, 0);
        vector<int> next(col+1, 0);

        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                int right = curr[j+1];
                int dignol = next[j+1];
                int down = next[j];
                if(matrix[i][j] == '1'){
                    curr[j] = 1 + min(right, min(dignol, down));
                    maxi = max(maxi, curr[j]);
                }else{
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return curr[0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // int maxi = 0;
        // int i = 0;
        // int j = 0;
        // solve(matrix, maxi, i, j);
        // return maxi*maxi;

        // int maxi = 0;
        // int row = matrix.size();
        // int col = matrix[0].size();
        // vector<vector<int>> dp(row, vector<int> (col, -1));
        // solveMem(matrix, maxi, 0, 0, dp);
        // return maxi*maxi;

        // int maxi = 0;
        // solveTab(matrix, maxi);
        // return maxi*maxi;

        int maxi = 0;
        solveSO(matrix, maxi);
        return maxi*maxi;
    }
};