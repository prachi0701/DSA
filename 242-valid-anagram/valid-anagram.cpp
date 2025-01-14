class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        vector<int> sCount(26, 0);
        for(int i=0; i<s.length(); i++){
            sCount[s[i] - 'a']++;
        }

        vector<int> tCount(26, 0);
        for(int i=0; i<t.length(); i++){
            tCount[t[i] - 'a']++;
        }

        if(sCount == tCount){
            return true;
        }else{
            return false;
        }
    }
};