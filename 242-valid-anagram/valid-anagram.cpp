class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        map<char, int> words;
        for(int i=0;i<s.length();i++){
            words[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            auto it=words.find(t[i]);
            if(it==words.end() || it->second <=0){
                return false;
            }else{
                words[t[i]]--;
            }
        }
        return true;
    }
};