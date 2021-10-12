class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n(s.size());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=n; j++){
                if(s[i] == s[j-1])
                    dp[i][j]=1+dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][n];
    }
};
