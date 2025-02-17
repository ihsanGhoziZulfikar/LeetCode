class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        stack<string> st;
        while(i<s.length()){
            string str;
            while(i<s.length() && s[i]==' ')i++;
            while(i<s.length() && s[i]!=' ')str+=s[i++];
            if(!str.empty()){
                st.push(str);
            }
        }
        string result;
        while(!st.empty()){
            result += st.top() + " ";
            st.pop();
        }
        result = result.substr(0, result.size()-1);

        return result;
    }
};