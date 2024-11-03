class Solution {
public:

    int solve(int index, int buy, int limit, vector<int>& prices){
        if(limit == 0){
            return 0;
        }
        if(index == prices.size()){
            return 0;
        }

        int profit = 0;
        if(buy == 1){
            int include = (-1)*prices[index] + solve(index+1, 0, limit, prices);
            int exclude = 0 + solve(index+1, 1, limit, prices);
            profit = max(include, exclude);
        }
        else{
            int include = prices[index] + solve(index+1, 1, limit-1, prices);
            int exclude = 0 + solve(index+1, 0, limit, prices);
            profit = max(include, exclude);
        }
        return profit;
    }


    int solveMem(int index, int buy, int limit, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(limit == 0){
            return 0;
        }
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }

        int profit = 0;
        if(buy == 1){
            int include = (-1)*prices[index] + solveMem(index+1, 0, limit, prices, dp);
            int exclude = 0 + solveMem(index+1, 1, limit, prices, dp);
            profit = max(include, exclude);
        }
        else{
            int include = prices[index] + solveMem(index+1, 1, limit-1, prices, dp);
            int exclude = 0 + solveMem(index+1, 0, limit, prices, dp);
            profit = max(include, exclude);
        }
        return dp[index][buy][limit] = profit;
    }


    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){
                    int profit = 0;
                    if(buy == 1){
                        int include = (-1)*prices[index] + dp[index+1][0][limit];
                        int exclude = 0 + dp[index+1][1][limit];
                        profit = max(include, exclude);
                    }
                    else{
                        int include = prices[index] + dp[index+1][1][limit-1];
                        int exclude = 0 + dp[index+1][0][limit];
                        profit = max(include, exclude);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }


    int solveSO(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){
                    int profit = 0;
                    if(buy == 1){
                        int include = (-1)*prices[index] + next[0][limit];
                        int exclude = 0 + next[1][limit];
                        profit = max(include, exclude);
                    }
                    else{
                        int include = prices[index] + next[1][limit-1];
                        int exclude = 0 + next[0][limit];
                        profit = max(include, exclude);
                    }
                    curr[buy][limit] = profit;
                }
                next = curr;
            }
        }
        return next[1][2];
    }


    int maxProfit(vector<int>& prices) {
        // return solve(0, 1, 2, prices);

        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solveMem(0, 1, 2, prices, dp);

        // return solveTab(prices);

        return solveSO(prices);
    }
};