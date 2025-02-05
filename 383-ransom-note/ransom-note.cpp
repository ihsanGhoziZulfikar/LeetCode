class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> words;
        for(int i=0;i<magazine.length();i++){
            if(words.find(magazine[i])==words.end()){
                words.insert({magazine[i],1});
            }else{
                words[magazine[i]]++;
            }
        }
        for(int i=0;i<ransomNote.length();i++){
            auto word=words.find(ransomNote[i]);
            if(word==words.end())return false;
            if(word->second==0)return false;
            word->second--;
        }
        return true;
    }
};