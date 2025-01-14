class Solution {
public:

    string solve(string& a){
        string ans = "";
        for(int i=0; i<a.length(); i++){
            int j = i;
            int cnt = 0;
            while(j<a.length() && a[i] == a[j]){
                cnt++;
                j++;
            }
            string temp = to_string(cnt);
            ans += temp;
            ans += a[i];
            i = j-1;
        }
        return ans;
    }

    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string a = "1";
        for(int i=1; i<n; i++){
            a = solve(a);
        }
        return a;
    }
};