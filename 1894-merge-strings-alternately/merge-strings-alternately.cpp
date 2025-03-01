class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string merged = "";
        while(i<word1.length() && j<word2.length()){
            merged = merged + word1[i] + word2[j];
            i++;
            j++;
        }
        if(i<word1.length()){
            merged = merged+word1.substr(i,word1.length()-i);
        }
        if(j<word2.length()){
            merged = merged+word2.substr(j,word2.length()-j);
        }
        return merged;
    }
};