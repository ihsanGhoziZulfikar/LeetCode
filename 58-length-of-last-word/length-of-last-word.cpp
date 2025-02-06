class Solution {
public:
    int lengthOfLastWord(string s) {
        int last=s.length()-1;
        while(s[last]==' ')last--;
        int first = last;
        while(first>=0 && s[first]!=' ')first--;
        return last-first;
    }
};