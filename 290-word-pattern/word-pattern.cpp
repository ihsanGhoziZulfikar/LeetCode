class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> words;
        map<char, string> words2;
        istringstream iss(s);

        string str;
        int i=0;
        while(iss>>str){
            auto it = words.find(str);
            auto it2 = words2.find(pattern[i]);
            if(it==words.end()){
                words[str]=pattern[i];
            }
            if(it2==words2.end()){
                words2[pattern[i]]=str;
            }
            if(words[str]!=pattern[i] || words2[pattern[i]]!=str){
                return false;
            }
            if(i<pattern.length()){
                i++;
            }else{
                return false;
            }
        }
        if(i<pattern.length())return false;
        return true;
    }
};