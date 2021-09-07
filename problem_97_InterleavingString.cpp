class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int ls1=s1.size(), ls2=s2.size(), ls3=s3.size();
        if(ls1 + ls2 != ls3) return false;
        
        vector<bool> v(ls2+1, true);
        vector<vector<bool>> dp(ls1+1, v);
        dp[0][0] = true;
        
        for(int i=1; i<=ls1; i++){
            if(s1[i-1] != s3[i-1]) dp[i][0] = false;
            else dp[i][0] = dp[i-1][0];
        }
        for(int i=1; i<=ls2; i++){
            if(s2[i-1] != s3[i-1]) dp[0][i] = false;
            else dp[0][i] = dp[0][i-1];
        }
        
        for(int i=1; i<=ls1; i++)
            for(int j=1; j<=ls2; j++){
                if(s1[i-1]==s3[i+j-1] && s2[j-1]!=s3[i+j-1]) dp[i][j] = dp[i-1][j];
                else if(s1[i-1]!=s3[i+j-1] && s2[j-1]==s3[i+j-1]) dp[i][j] = dp[i][j-1];
                else if(s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1]) dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                else dp[i][j] = false;
            }
        
        return dp[ls1][ls2];
    }
};
