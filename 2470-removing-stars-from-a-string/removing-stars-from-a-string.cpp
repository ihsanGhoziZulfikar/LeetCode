class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=1;i<s.length();i++){
            if(s[i]=='*'){
                // cout << "before: " << s << " " << i << endl;
                s.erase(i-1,2);
                // cout << s << endl;
                // s.erase(s.begin()+i-1);
                i-=2;
            }
        }
        return s;
    }
};

// class Solution {
// public:
//     string removeStars(string s) {
//         stack<char> st;
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='*'){
//                 st.pop();
//             }else{
//                 st.push(s[i]);
//             }
//         }
//         string res;
//         while(!st.empty()){
//             res=st.top()+res;
//             st.pop();
//         }
//         return res;
//     }
// };