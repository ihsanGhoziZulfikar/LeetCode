class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> words;
        map<char, char> words2;
        for(int i=0;i<s.length();i++){
            auto it=words.find(s[i]);
            auto it2=words2.find(t[i]);
            if(it==words.end()){
                words[s[i]]=t[i];
            }
            if(it2==words2.end()){
                words2[t[i]]=s[i];
            }
            if(words[s[i]]!=t[i] || words2[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};