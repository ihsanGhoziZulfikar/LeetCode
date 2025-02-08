class Solution {
public:
    static bool longer_str(string s1, string s2){
        return s1.length()<s2.length();
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(),longer_str);
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            if(prefix=="")return prefix;
            for(int j=0;j<prefix.length() && j<strs[i].length();j++){
                if(prefix[j]!=strs[i][j]){
                    prefix=prefix.substr(0,j);
                }
            }
        }
        return prefix;
    }
};