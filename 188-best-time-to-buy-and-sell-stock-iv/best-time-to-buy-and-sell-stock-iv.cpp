class Solution {
public:

    int solveTab(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int index = n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){
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
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        return solveTab(k, prices);
    }
};