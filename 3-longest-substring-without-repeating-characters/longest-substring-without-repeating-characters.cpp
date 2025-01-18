class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }


        int maxi = 1;

        for(int i=0; i<s.length(); i++){
            int cnt = 1;
            unordered_set<int> set;
            set.insert(s[i]);
            for(int j=i+1; j<s.length(); j++){
                if(set.find(s[j]) != set.end()){
                    break;
                }
                else{
                    set.insert(s[j]);
                    cnt++;
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};