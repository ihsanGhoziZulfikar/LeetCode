class Solution {
public:
    bool isVowel(char c){
        return ( c=='a' || c=='i' || c=='u' || c=='e' || c=='o' );
    }
    int maxVowels(string s, int k) {
        int maxi=0;
        int curr=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                curr++;
            }
        }
        maxi=curr;
        for(int i=k;i<s.length();i++){
            if(isVowel(s[i])){
                curr++;
            }
            if(isVowel(s[i-k])){
                curr--;
            }
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};