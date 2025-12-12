class Solution {
public:
    string longestPalindrome(string s) {
        string res = s.substr(0,1);
        string temp;
        for(int i=0;i<s.length();i++){
            if(i+1<s.length() && s[i]==s[i+1]){
                temp = s.substr(i,2);
                int start=i-1, end=i+2;
                while(start>=0 && end<s.length() && s[start] == s[end]){
                    temp = s[start] + temp + s[end];
                    start--;
                    end++;
                }
                if(temp.length()>res.length()){
                    res = temp;
                }
            }
            if(i+2<s.length() && s[i]==s[i+2]){
                temp = s.substr(i,3);
                int start=i-1, end=i+3;
                while(start>=0 && end<s.length() && s[start] == s[end]){
                    temp = s[start] + temp + s[end];
                    start--;
                    end++;
                }
                if(temp.length()>res.length()){
                    res = temp;
                }
            }
        }
        return res;
    }
};