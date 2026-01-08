class Solution {
public:
    int countAscii(string str){
        int result = 0;
        for(int i=0;i<str.length();i++){
            result += (int)str[i];
        }
        return result;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(),0));
        vector<vector<int>> dp_ascii(s1.length(), vector<int>(s2.length(),0));

        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                if(s1[i] == s2[j]){
                    if(i>0 && j>0){
                        dp[i][j] = dp[i-1][j-1]+(int)s1[i];
                    }else{
                        dp[i][j] = (int)s1[i];
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

        // int lcs_ascii = countAscii(dp[s1.length()-1][s2.length()-1]);
        int s1_ascii = countAscii(s1);
        int s2_ascii = countAscii(s2);

        // cout << dp[s1.length()-1][s2.length()-1] << " " << s1_ascii << " " << s2_ascii << endl;

        return s1_ascii + s2_ascii - 2*dp[s1.length()-1][s2.length()-1];
        // return dp[s1.length()-1][s2.length()-1];
    }
};

