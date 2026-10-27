class Solution {
public:
    map<char, char> m = {{'(',')'}, {'{','}'}, {'[',']'}};

    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty()){
                if(m[st.top()] == s[i]){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};