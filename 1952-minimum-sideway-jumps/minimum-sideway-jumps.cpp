class Solution {
public:

    int solveMem(vector<int>& obstacles, int currpos, int lane, int n, vector<vector<int>>& dp){
        if(currpos == n){
            return 0;
        }
        if(dp[lane][currpos] != -1){
            return dp[lane][currpos];
        }
        if(obstacles[currpos+1] != lane){
            // dp[lane][currpos] = 0;
            return solveMem(obstacles, currpos+1, lane, n, dp);
        }else{
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(i != lane && obstacles[currpos] != i){
                    ans = min(ans , 1 + solveMem(obstacles, currpos, i, n, dp));
                }
            }
            dp[lane][currpos] = ans;
            return dp[lane][currpos];
        }
    }

    int solveTab(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int currpos = n-1; currpos >=0; currpos--){
            for(int lane = 1; lane <= 3; lane++){
                if(obstacles[currpos+1] != lane){
                    dp[lane][currpos] = dp[lane][currpos+1];
                }else{
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(i != lane && obstacles[currpos] != i){
                            ans = min(ans, 1 + dp[i][currpos+1]);
                        }
                    }
                    dp[lane][currpos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));         
    }

    int solveSpaceOpt(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<int> curr(4, 1e9);
        vector<int> next(4, 1e9);
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int currpos = n-1; currpos >=0; currpos--){
            for(int lane = 1; lane <= 3; lane++){
                if(obstacles[currpos+1] != lane){
                    curr[lane] = next[lane];
                }else{
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(i != lane && obstacles[currpos] != i){
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1+next[1], 1+next[3]));         
    }

    int minSideJumps(vector<int>& obstacles) {
        // int currpos = 0;
        // int lane = 2;
        // int n = obstacles.size()-1;
        // vector<vector<int>> dp(4, vector<int>(n, -1));
        // int ans = solve(obstacles, currpos, lane, n, dp);
        // return ans;

        // return solveTab(obstacles);

        return solveSpaceOpt(obstacles);
    }
};