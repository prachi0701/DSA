class Solution {
public:
    int myAtoi(string s) {
        string st;

        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] == '.'){
                break;
            }
            else if(!st.empty() && !isdigit(s[i])){
                break;
            }
            else if(s[i] == ' '){
                continue;
            }
            else{
                st.push_back(s[i]);
            }
        }

        long sign = 1;
        long ans = 0;
        for(int i=0; i<st.length(); i++){
            if(st[i] == '-'){
                sign *= -1;
            }
            else if(st[i] == '+'){
                sign *= 1;
            }
            else{
                long a = st[i] - '0';
                ans = ans*10 + a;
                if(sign == -1 && sign*ans < INT_MIN) return INT_MIN;
                if(sign == 1 && sign*ans > INT_MAX) return INT_MAX;

            }
        }
        return (int)(ans*sign);
    }
};