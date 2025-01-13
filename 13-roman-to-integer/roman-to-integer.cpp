class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        vector<int> nums;
        for(int i=0; i<n; i++){
            if(s[i] == 'I'){
                nums.push_back(1);
            }
            else if(s[i] == 'V'){
                nums.push_back(5);
            }
            else if(s[i] == 'X'){
                nums.push_back(10);
            }
            else if(s[i] == 'L'){
                nums.push_back(50);
            }
            else if(s[i] == 'C'){
                nums.push_back(100);
            }
            else if(s[i] == 'D'){
                nums.push_back(500);
            }
            else if(s[i] == 'M'){
                nums.push_back(1000);
            }
        }

        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i+1] > nums[i]){
                ans -= nums[i];
            }
            else{
                ans += nums[i];
            }
        }
        ans += nums[n-1];
        return ans;
    }
};