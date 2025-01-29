class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return (!isalpha(c) && !isdigit(c)); } ), s.end());
        if(s.length()==0) return true;
        for(int i=0;i<=s.length()/2;i++){
            if(tolower(s[i])!=tolower(s[s.size()-i-1])){
                return false;
            }
        }
        cout << s;
        return true;
    }
};