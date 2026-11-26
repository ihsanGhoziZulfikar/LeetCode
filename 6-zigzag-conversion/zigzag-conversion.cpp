class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(s.length(), "");
        int n=0,direction=1;
        string res="";

        for(int i=0;i<s.length();i++){
            v[n]+=s[i];

            n+=direction;
            if(numRows>1 && (n>=numRows || n<0)){
                direction*=-1;
                n+=direction;
                n+=direction;
            }
        }
        for(int i=0;i<v.size();i++){
            res+=v[i];
            // cout << v[i] << endl;
        }
        return res;
    }
};