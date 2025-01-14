class Solution {
public:

    int LCS(string text1, string text2){
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


    int minInsertions(string s) {

        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        string b = s;
        reverse(b.begin(), b.end());
        int cnt = LCS(s, b);
        int ans = n-cnt;
        return ans;
    }
};