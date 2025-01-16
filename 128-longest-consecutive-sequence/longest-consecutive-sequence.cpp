class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> s;

        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int ans = 1;

        for(auto i : s){
            if(s.find(i-1) == s.end()){
                int cnt = 1;
                int x = i+1;
                while(s.find(x) != s.end()){
                    x++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};