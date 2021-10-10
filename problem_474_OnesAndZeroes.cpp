class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> v(n+1, 0);
        vector<vector<int>> dp(m+1, v);
        
        for(string str:strs){
          int zeros(0);
          for(char c:str)
            if(c == '0')
              zeros++;
          int ones(str.size()-zeros);
          for(int i=m; i>=zeros; i--)
            for(int j=n; j>=ones; j--)
              dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
        }
        return dp[m][n];
    }
};
