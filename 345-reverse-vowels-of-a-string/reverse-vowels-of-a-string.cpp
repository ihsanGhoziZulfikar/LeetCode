class Solution {
public:
    bool isVowel(char c){
        if( c=='a' || c=='i' || c=='u' || c=='e' || c=='o' ||
            c=='A' || c=='I' || c=='U' || c=='E' || c=='O'){
            return true;
        }

        return false;
    };
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            while(!isVowel(s[i]) && i<j)i++;
            while(!isVowel(s[j]) && j>i)j--;
            if(i<j){
                s[i]=s[i]^s[j];
                s[j]=s[i]^s[j];
                s[i]=s[i]^s[j];

                i++;
                j--;
            }
        }
        return s;
    }
};