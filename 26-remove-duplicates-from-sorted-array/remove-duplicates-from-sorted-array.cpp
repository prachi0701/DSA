class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;

        while(j < nums.size()){
            if(nums[j] == nums[i]){
                j++;
            }
            else{
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;   //we have to return size3 but i store index so we do i+1
    }
};