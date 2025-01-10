class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        // int start = intervals[0][0];
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        int i = 0;
        int j = 0;

        while(j < n){
            if(j+1 < n && end >= intervals[j+1][0]){
                end = max(end, intervals[j+1][1]);
                j++;
            }else{
                vector<int> temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(end);
                ans.push_back(temp);
                i = j+1;
                j++;
                if(j < n){
                    end = intervals[i][1];
                }
            }
        }
        return ans;
    }
};