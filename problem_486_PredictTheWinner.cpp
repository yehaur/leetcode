class Solution {
public:
    int calc(int i, int j, vector<vector<int>>& dp, vector<int>& v){
        if(i > j) return 0;
        if(i == j) return v[i];
        if(j-i == 1) return max(v[i], v[j]);
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int way1 = v[i]+min(calc(i+2, j, dp, v), calc(i+1, j-1, dp, v)); // player1 select the first element
        int way2 = v[j]+min(calc(i+1,j-1,dp, v), calc(i, j-2, dp, v)); // if player2 select the end element
        dp[i][j] = max(way1, way2);
        return dp[i][j];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n(nums.size()), s(std::accumulate(nums.begin(), nums.end(), 0));
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int res = calc(0, n-1, dp, nums);
        return res >= s-res;
    }
};
