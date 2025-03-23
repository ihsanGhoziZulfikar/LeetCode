class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        map<char, int> m1,m2;
        vector<int> v1,v2;
        for(int i=0;i<word1.length();i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        for(auto it=m1.begin();it!=m1.end();++it){
            if(m2[it->first]==0){
                return false;
            }
            v1.push_back(it->second);
        }
        for(auto it=m2.begin();it!=m2.end();++it){
            if(m1[it->first]==0){
                return false;
            }
            v2.push_back(it->second);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }

        return true;
    }
};