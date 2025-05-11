class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        int med1 = -1;
        int med2 = -1;
        int n = nums1.size() + nums2.size();
        int ind1 = n/2;
        int ind2 = n/2 - 1;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1) med1 = nums1[i];
                if(cnt == ind2) med2 = nums1[i];
                i++;
                cnt++;
            }else{
                if(cnt == ind1) med1 = nums2[j];
                if(cnt == ind2) med2 = nums2[j];
                j++;
                cnt++;
            }
        }

        while(i < nums1.size()){
            if(cnt == ind1) med1 = nums1[i];
            if(cnt == ind2) med2 = nums1[i];
            i++;
            cnt++;
        }
        while(j < nums2.size()){
            if(cnt == ind1) med1 = nums2[j];
            if(cnt == ind2) med2 = nums2[j];
            j++;
            cnt++;
        }

        double ans = 0;
        int mid = n/2;
        if(n%2 == 0){
            ans = (med1 + med2*(1.0))/2;
        }
        else{
            ans = med1*(1.0);
        }
        return ans;
    }
};