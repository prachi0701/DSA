class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> set;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1;
                int high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else{
                        set.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }
        for(auto i : set){
            ans.push_back(i);
        }
        return ans;
    }
};