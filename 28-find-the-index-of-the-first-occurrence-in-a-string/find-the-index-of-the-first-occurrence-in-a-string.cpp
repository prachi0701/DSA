class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.length(); i++){
            int j;
            for(j=0; j<needle.length(); j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j == needle.length()){
                return i;
            }
        }
        return -1;
    }
};