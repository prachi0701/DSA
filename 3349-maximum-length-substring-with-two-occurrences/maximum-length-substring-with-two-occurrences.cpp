class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0;
        int j = 1;
        vector<int> v(26, 0);
        v[s[0] - 'a']++;
        int maxi = 0;

        while(j < s.length()){
            if(v[s[j] - 'a'] + 1 > 2){
                v[s[i] - 'a']--;
                i++;
            }
            else{
                v[s[j] - 'a']++;
                j++;
            }
            maxi = max(maxi, j-i);
        }
        return maxi;
    }
};