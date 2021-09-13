class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int l = 0;
        while(l < n){
            if(!l && nums[l]!=nums[l+1]) return nums[l];
            l++; 
            int r = l*2;
            if(r<n && nums[r]!=nums[r-1]){
                if(r == n-1) return nums[r];
                if(nums[r] != nums[r+1]) return nums[r];
            }
        }
        return -1;
    }
};
