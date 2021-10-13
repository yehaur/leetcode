class Solution {
public:
    string longestPalindrome(string s) {
        int n(s.size()), len(1);
        string ans = s.substr(0,1);
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++) dp[i][i] = 1;
        
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++){
                if(s[i] != s[j])
                    dp[i][j] = -1;
                else{
                    int l(i+1), r(j-1);
                    while(l <= r){
                        if(s[l] != s[r]){
                            dp[i][j] = -1;
                            dp[l][r] = -1;
                            break;
                        }
                        if(l != r)
                            dp[i][j] = max(dp[i][j], 2+dp[l][r]);
                        else
                            dp[i][j] = max(dp[i][j], 1+dp[l][r]);
                        l++;
                        r--;
                    }
                }
                if(len < dp[i][j]){
                    len = j - i + 1;
                    ans = s.substr(i, len);
                }
            }
                    
        return ans;
    }
};
