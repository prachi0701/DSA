class Solution {
public:

    int solve(int index, int buy, vector<int>& prices){
        if(index >= prices.size()){
            return 0;
        }

        int profit = 0;
        if(buy == 1){
            int include = (-1)*prices[index] + solve(index+1, 0, prices);
            int exclude = 0 + solve(index+1, 1, prices);
            profit = max(include, exclude);
        }
        else{
            int include = prices[index] + solve(index+2, 1, prices);
            int exclude = 0 + solve(index+1, 0, prices);
            profit = max(include, exclude);
        }
        return profit;
    }


    int solveMem(int index, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(index >= prices.size()){
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
        }
        else{
            int include = prices[index] + solveMem(index+2, 1, prices, dp);
            int exclude = 0 + solveMem(index+1, 0, prices, dp);
            profit = max(include, exclude);
        }
        return dp[index][buy] = profit;
    }


    int maxProfit(vector<int>& prices) {
        // return solve(0, 1, prices);

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveMem(0, 1, prices, dp);
    }
};