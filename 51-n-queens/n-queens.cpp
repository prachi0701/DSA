class Solution {
public:

    bool isSafe(int col, int row, vector<string> temp, int n){
        int dumCol = col;
        int dumRow = row;

        // for upper diagnol
        while(dumRow >= 0 && dumCol >= 0){
            if(temp[dumRow][dumCol] == 'Q'){
                return false;
            }
            dumRow--;
            dumCol--;
        }

        // for left side
        dumRow = row;
        dumCol = col;
        while(dumCol >= 0){
            if(temp[dumRow][dumCol] == 'Q'){
                return false;
            }
            dumCol--;
        }

        // for lower diagonal
        dumRow = row;
        dumCol = col;
        while(dumCol >= 0 && dumRow < n){
            if(temp[dumRow][dumCol] == 'Q'){
                return false;
            }
            dumCol--;
            dumRow++;
        }
        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<string> temp, int n){
        if(col == n){
            ans.push_back(temp);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(col, row, temp, n)){
                temp[row][col] = 'Q';
                solve(col+1, ans, temp, n);
                temp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            temp[i] = s;
        }
        solve(0, ans, temp, n);
        return ans;
    }
};