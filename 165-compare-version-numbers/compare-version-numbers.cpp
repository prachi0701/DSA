class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;

        while(i < version1.length() || j < version2.length()){
            string temp1 = "";
            while(i < version1.length() && version1[i] != '.'){
                temp1 += version1[i];
                i++;
            }
            string temp2 = "";
            while(j < version2.length() && version2[j] != '.'){
                temp2 += version2[j];
                j++;
            }
            i++;
            j++;

            int num1 = 0;
            if(temp1 != ""){
                num1 = stoi(temp1);
            }
            int num2 = 0;
            if(temp2 != ""){
                num2 = stoi(temp2);
            }

            if(num1 < num2){
                return -1;
            }
            else if(num1 > num2){
                return 1;
            }
        }

        return 0;
    }
};