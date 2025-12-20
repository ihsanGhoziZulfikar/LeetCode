class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int longest=1;
        string longest_str = s.substr(0,1);
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
            if(i+1<s.length()){
                if(s[i]==s[i+1]){
                    dp[i][i+1]=2;
                    longest=2;
                    longest_str = s.substr(i, 2);
                }else{
                    dp[i][i+1]=0;
                }
            }
        }
        int col=2;
        while(col<s.length()){
            int i=0;
            int j=col;
            while(j<s.length()){
                if(s[i]==s[j] && dp[i+1][j-1]>0){
                    dp[i][j] = dp[i+1][j-1] + 2;
                    if(j-i+1 > longest){
                        longest = j-i+1;
                        longest_str=s.substr(i, j-i+1);
                    }
                }
                i++;
                j++;
            }
            col++;
        }

        return longest_str;
    }
};