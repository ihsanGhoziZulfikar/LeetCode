class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res=0;
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int res;
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(tokens[i] == "+"){
                    res = b+a;
                } else if(tokens[i] == "-"){
                    res = b-a;
                } else if(tokens[i] == "*"){
                    res = b*a;
                } else if(tokens[i] == "/"){
                    res = b/a;
                }
                s.push(res);
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};