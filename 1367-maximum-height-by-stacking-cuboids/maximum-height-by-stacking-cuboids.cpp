class Solution {
public:

    bool check(vector<int>& a, vector<int>& b){
        if(a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]){
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int curr_index = n-1; curr_index >= 0; curr_index--){
            for(int prev_ind = curr_index-1; prev_ind >= -1; prev_ind--){
                int exclude = next[prev_ind+1];
                int include = 0;
                if(prev_ind == -1 || check(cuboids[curr_index], cuboids[prev_ind])){
                    include = cuboids[curr_index][2] + next[curr_index+1];
                }
                curr[prev_ind+1] = max(exclude, include);
            }
            next = curr;
        }
        return next[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // step 1 sort inside wala vector
        for(auto &a :  cuboids){
            sort(a.begin(), a.end());
        }
        // step 2 sort vector
        sort(cuboids.begin(), cuboids.end());
        return solve(cuboids);
    }
};