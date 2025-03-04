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
        deque<char> dq;
        int i=0,j=s.length()-1;
        while(i<j){
            while(!isVowel(s[i]) && i<j)i++;
            while(!isVowel(s[j]) && j>i)j--;
            // cout << i << " " << j << endl;
            if(i<j){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
        }
        return s;
    }
};