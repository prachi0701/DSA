class Solution {
public:

    bool isSubstring(string a, string b){
        for(int i=0; i<a.length(); i++){
            int j;
            for(j=0; j<b.length(); j++){
                if(a[i+j] != b[j]){
                    break;
                }
            }
            if(j == b.length()){
                return true;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {\
        // int n = (b.length() + a.length() - 1) / a.length();

        // 4 possible way
        // x n*a x ----- x n*a ------- n*a x ----- n*a

        string temp = a;
        int cnt = 1;

        while(a.length() < b.length()){
            a += temp;
            cnt++; 
        }

        if(isSubstring(a, b) == true){
            return cnt;
        }

        a += temp;
        if(isSubstring(a, b) == true){
            return cnt+1;
        }

        a += temp;
        if(isSubstring(a, b) == true){
            return cnt+2;
        }

        return -1;
    }
};