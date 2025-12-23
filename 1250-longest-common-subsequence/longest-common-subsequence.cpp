class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(),0));
        // dp[0][0] = text1[0] == text2[0]? 1:0;
        // map<char,int> dp;

        for(int i=0;i<text1.length();i++){
            for(int j=0;j<text2.length();j++){
                if(text1[i] == text2[j]){
                    if(i>0 && j>0){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }else{
                        dp[i][j] = 1;
                    }
                    
                }else{
                    if(i>0 && j>0){
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }else if (i>0){
                        dp[i][j] = dp[i-1][j];
                    }else if (j>0){
                        dp[i][j] = dp[i][j-1];
                    }else{
                        dp[i][j] = 0;
                    }
                    
                }
            }
        }

        return dp[text1.length()-1][text2.length()-1];
    }
};

/*
ace
abcde
*/