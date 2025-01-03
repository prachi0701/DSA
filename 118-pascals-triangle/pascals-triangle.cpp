class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>> ans;
        // vector<int> v;
        // v.push_back(1);
        // ans.push_back(v);
        // if(numRows == 1){
        //     return ans;
        // }
        // v.push_back(1);
        // ans.push_back(v);
        // if(numRows == 2){
        //     return ans;
        // }
        
        // for(int i=2; i<numRows; i++){
        //     vector<int> temp;
        //     temp.push_back(1);
        //     int l = 0;
        //     int m = 1;
        //     while(m < ans[i-1].size()){
        //         temp.push_back(ans[i-1][l] + ans[i-1][m]);
        //         l++;
        //         m++;
        //     }
        //     temp.push_back(1);
        //     ans.push_back(temp);
        // }
        // return ans;


        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);

        for(int row=2; row<=numRows; row++){
            vector<int> temp;
            temp.push_back(1);
            int element = 1;
            for(int col=1; col<row; col++){
                element = element * (row-col);
                element = element / col;
                temp.push_back(element);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};