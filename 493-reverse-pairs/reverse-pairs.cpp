class Solution {
public:

    // void merge(vector<int>& nums, int low, int mid, int high){
    //     vector<int> temp(high - low + 1);
    //     int left = low;
    //     int right = mid+1;

    //     while(left <= mid && right <= high){
    //         if(nums[left] <= nums[right]){
    //             temp.push_back(nums[left]);
    //         }
    //         else{
    //             temp.push_back(nums[right]);
    //         }
    //     }
    //     while(left <= mid){
    //          temp.push_back(nums[left]);
    //     }
    //     while(right <= high){
    //         temp.push_back(nums[right]);
    //     }

    //     for(int i=low; i<=high; i++){
    //         nums[i] = temp[i-low];
    //     }
    // }

    // int countPair(vector<int>& nums, int low, int mid, int high){
    //     int cnt = 0;
    //     int right = mid+1;
    //     for(int i=low; i<=mid; i++){
    //         while(right <= high && nums[i] > 2*nums[right]){
    //             right++;
    //         }
    //         cnt += right - (mid+1);
    //     }
    //     return cnt;
    // }

    // int mergeSort(vector<int>& nums, int low, int high){
    //     int cnt = 0;
    //     if(low >= high){
    //         return 0;
    //     }
    //     int mid = (low+high)/2;
    //     cnt += mergeSort(nums, low, mid);
    //     cnt += mergeSort(nums, mid+1, high);
    //     cnt += countPair(nums, low, mid, high);
    //     merge(nums, low, mid, high);
    //     return cnt;
    // }



    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }

    int reversePairs(vector<int>& nums) {
        // return mergeSort(nums, 0, nums.size()-1);


        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
};