class Solution {
public:
    bool map_compare(map<char, int> map1, map<char, int> map2){
        if(map1.size()!=map2.size())return false;
        for(int i=0;i<map1.size();i++){
            if(map1[i]!=map2[i])return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> words_vec;
        vector<string> words_count;
        for(int i=0;i<strs.size();i++){
            string words = strs[i];
            sort(words.begin(), words.end());
            int anagram=false;

            for(int j=0;j<words_count.size();j++){
                if(words_count[j]==words){
                    anagram=true;
                    words_vec[j].push_back(strs[i]);
                }
            }
            if(!anagram){
                words_vec.push_back({strs[i]});
                words_count.push_back(words);
            }
        }
        return words_vec;
    }
};