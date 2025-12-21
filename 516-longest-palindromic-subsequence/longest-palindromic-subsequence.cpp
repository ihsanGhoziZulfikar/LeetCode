class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int longest=1;
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
            if(i+1<s.length()){
                if(s[i]==s[i+1]){
                    dp[i][i+1]=2;
                    longest=2;
                }else{
                    dp[i][i+1]=1;
                }
            }
        }

        int col = 2;
        while(col<s.length()){
            int i=0;
            int j=col;
            while(j<s.length()){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }

                longest = max(longest, dp[i][j]);
                i++;
                j++;
            }
            col++;
        }

        return longest;
    }
};