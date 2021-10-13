// Seems DP method is slower than two pointer!

class Solution {
public:
    string longestPalindrome(string s) {
        int n(s.size()), len(1);
        string ans = s.substr(0,1);
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++) dp[i][i] = 1;
        
        for(int gap=0; gap<n; gap++)
            for(int i=0, j=i+gap; j<n; i++, j++){
                if(s[i] == s[j]){
                    if(j==i+1) dp[i][j] = 1;
                    else if(j > i) dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j] && gap+1>len){
                    len = gap+1;
                    ans = s.substr(i, len);
                }
            }
                    
        return ans;
    }
};
