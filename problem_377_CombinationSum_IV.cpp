class Solution {
public:    
    int combinationSum4(vector<int>& nums, int target) {
        /*sort(nums.begin(), nums.end());
        while(nums.size() && nums.back()>target)
            nums.pop_back();
        if(nums[0] > target) return 0;*/
        
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            for(int n:nums){
                if(i-n >= 0)
                    dp[i] = dp[i]+dp[i-n];
            }
        }
        
        return dp[target];
    }
};
