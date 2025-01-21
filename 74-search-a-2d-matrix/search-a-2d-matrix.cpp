class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            if(matrix[i][0] <= target && matrix[i][col-1] >= target){
                int start = 0;
                int end = col-1;
                int mid = (start + end)/2;
                while(start <= end){
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    else if(matrix[i][mid] > target){
                        end = mid - 1;
                    }else{
                        start = mid + 1;
                    }
                    mid = (start + end)/2;
                }
            }
        }
        return false;
    }
};