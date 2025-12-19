class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<int,bool> m;
        m[0] = true;
        for(int i=0;i<s.length();i++){
            if(m[i]){
                for(int j=0;j<wordDict.size();j++){
                    int len = wordDict[j].length();
                    if(len <= s.length()-i && wordDict[j] == s.substr(i,len)){
                        m[i+len]=true;
                    }
                }
            }
        }
        return m[s.length()];
    }
};