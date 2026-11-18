class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        stack<int> ops;
        int res=0;
        int op=1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+'){
                op=1;
            }else if (s[i]=='-'){
                op=-1;
            }else if(s[i]=='('){
                st.push(res);
                ops.push(op);
                res=0;
                op=1;
            }else if(s[i]==')'){
                res*=ops.top();
                res+=st.top();

                st.pop();
                ops.pop();
            }else if(isdigit(s[i])){
                long long d=s[i]-'0';
                while(i+1<s.length() && isdigit(s[i+1])){
                    i++;
                    d=d*10+(s[i]-'0');
                }
                res+=(op*d);
            }
        }

        return res;
    }
};