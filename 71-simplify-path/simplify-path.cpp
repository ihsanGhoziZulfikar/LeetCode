class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        while(i<path.length()){
            int i_dot=0, i_dot_r=0, i_slash=0, i_slash_r=0, i_word=0, i_word_r=0;
            string dot;
            i_dot = i;
            while(i<path.length() && path[i]=='.'){
                i++;
                dot+=".";
            }
            i_dot_r = i-i_dot;
            i_slash = i;
            while(i<path.length() && path[i]=='/'){
                i++;
            }
            i_slash_r = i-i_slash;
            if(i_dot_r==2 && (i_slash_r>=1 || i==path.length())){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(i_dot_r>2 && ((i_slash<path.length() && path[i_slash]=='/') || i==path.length())){
                st.push(dot);
            }
            string current;
            i_word=i;
            while(i<path.length() && path[i]!='.' && path[i]!='/'){
                current+=path[i++];
            }
            i_word_r=i-i_word;
            if(i_word_r>0){
                while(i<path.length()&& path[i]!='/'){
                    current+=path[i++];
                }
            }
            if(i_slash_r==0 && i-i_word>0)current = dot+current;
            // cout << i_slash << "[]" << i_word << endl;
            if(!current.empty()) st.push(current);
        }
        string result;
        if(st.empty()){
            result = "/";
        }
        while(!st.empty()){
            result = "/" + st.top() + result;
            // cout << st.top() << endl;
            st.pop();
        }
        return result;
    }
};
