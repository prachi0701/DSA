class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        int index = 0;
        stack<string> st;
        string temp = "";

        while(index < s.length()){
            if(s[index] == ' '){
                if(temp != ""){
                    st.push(temp);
                    temp = "";
                }
            }
            else{
                temp.push_back(s[index]);
            }
            index++;
        }

        string ans = "";

        while(st.size() > 1){
            string temp = st.top();
            ans += temp;
            ans.push_back(' ');
            st.pop();
        }
        ans += st.top();
        return ans;
    }
};