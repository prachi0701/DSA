class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for(int i=0; i<strs[0].length(); i++){
            char ch = strs[0][i];
            bool match = true;
            for(int j=1; j<strs.size(); j++){
                if(strs[j].length() < i || strs[j][i] != ch){
                    match = false;
                    break;
                    
                }
            }
            if(match == true){
                ans.push_back(ch);
            }else{
                break;
            }
        }
        return ans;
    }
};