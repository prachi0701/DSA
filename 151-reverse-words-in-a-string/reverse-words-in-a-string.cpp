class Solution {
public:

    string reverseWords(string s) {
        stack<string> st;
        string str;
        s += " ";
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' '){
                str += s[i];
            }
            else if(str != ""){
                st.push(str);
                str = "";
            }
        }
        string ans = "";
        while(st.size() != 1){
            ans += st.top() + " ";
            st.pop();
        }
        ans += st.top();
        st.pop();
        return ans;
    }
};