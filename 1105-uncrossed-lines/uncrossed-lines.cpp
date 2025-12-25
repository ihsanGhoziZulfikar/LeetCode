class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    if(i>0 && j>0){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }else{
                        dp[i][j] = 1;
                    }
                }else{
                    if(i>0 && j>0){
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                    else if(i>0){
                        dp[i][j] = dp[i-1][j];
                    }
                    else if(j>0){
                        dp[i][j] = dp[i][j-1];
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[nums1.size()-1][nums2.size()-1];
    }
};