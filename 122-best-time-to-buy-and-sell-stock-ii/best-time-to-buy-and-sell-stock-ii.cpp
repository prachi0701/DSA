class Solution {
public:

    int solve(int index, int buy, vector<int>& prices){
        if(index == prices.size()){
            return 0;
        }
        
        int profit = 0;
        if(buy == 1){
            int include = (-1)*prices[index] + solve(index+1, 0, prices);     //buying
            int exclude = 0 + solve(index+1, 1, prices);       //not buying
            profit = max(include, exclude);
        }else{
            int include = prices[index] + solve(index+1, 1, prices);    //selling
            int exclude = 0 + solve(index+1, 0, prices);               // not selling
            profit = max(include, exclude);
        }
        return profit;
    }


    int solveMem(int index, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }        

        int profit = 0;
        if(buy == 1){
            int include = (-1)*prices[index] + solveMem(index+1, 0, prices, dp);
            int exclude = 0 + solveMem(index+1, 1, prices, dp);
            profit = max(include, exclude);
        }else{
            int include = prices[index] + solveMem(index+1, 1, prices, dp);
            int exclude = 0 + solveMem(index+1, 0, prices, dp);
            profit = max(include, exclude);
        }
        return dp[index][buy] = profit;
    }


    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
                if(buy == 1){
                    int include = (-1)*prices[index] + dp[index+1][0];
                    int exclude = 0 + dp[index+1][1];
                    profit = max(include, exclude);
                }else{
                    int include = prices[index] + dp[index+1][1];
                    int exclude = 0 + dp[index+1][0];
                    profit = max(include, exclude);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSO(vector<int>& prices){
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
                if(buy == 1){
                    int include = (-1)*prices[index] + next[0];
                    int exclude = 0 + next[1];
                    profit = max(include, exclude);
                }else{
                    int include = prices[index] + next[1];
                    int exclude = 0 + next[0];
                    profit = max(include, exclude);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }


    int maxProfit(vector<int>& prices) {
        // return solve(0, 1, prices);

        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveMem(0, 1, prices, dp);

        // return solveTab(prices);

        return solveSO(prices);
    }
};