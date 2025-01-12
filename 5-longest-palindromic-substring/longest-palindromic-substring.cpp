class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = 1;
        int start = 0;

        for(int i=0; i<n; i++){

            for(int j=0; j<=1; j++){
                int low = i;
                int high = i+j;

                while(low>=0 && high <n && s[low] == s[high]){
                    if(high-low +1 > maxi){
                        start = low;
                        maxi = high-low +1;
                    }
                    low--;
                    high++;
                }
            }
        }

        string ans = s.substr(start, maxi);
        return ans;
    }
};