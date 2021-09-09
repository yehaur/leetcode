class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans, nums;
        vector<char> opers;
        string snum;
        for(int i=0; i<expression.size(); i++){
            if(expression[i]=='+' || 
               expression[i]=='-' || 
               expression[i]=='*'){
                opers.push_back(expression[i]);
                if(snum.size()) nums.push_back(stoi(snum));
                snum = "";
            }else
                snum.push_back(expression[i]);
        }
        if(snum.size()) nums.push_back(stoi(snum));
        
        int n = nums.size();
        vector<vector<unordered_multiset<int>>> dp(n+1, vector<unordered_multiset<int>>(n+1));
        
        for(int i=0; i<n; i++){
            unordered_multiset<int> us;
            us.insert(nums[i]);
            dp[i][i] = us;
        }
        
        for(int len=1; len<n; len++){
            for(int left = 0; left+len < n; left++){
                int right = left + len;
                unordered_multiset<int> us;
                for(int pos=left; pos<right; pos++){
                    int tmp;
                    for(int ele1:dp[left][pos]){
                        for(int ele2:dp[pos+1][right]){
                            if(opers[pos] == '*')
                                tmp = ele1 * ele2;
                            else if(opers[pos] == '+')
                                tmp = ele1 + ele2;
                            else
                                tmp = ele1 - ele2;
                            us.insert(tmp);
                        }
                    }
                   // dp[left][right] = us;
                }
                dp[left][right] = us;
            }
        }
        for(int i:dp[0][n-1]) ans.push_back(i);
        return ans;
    }
};
