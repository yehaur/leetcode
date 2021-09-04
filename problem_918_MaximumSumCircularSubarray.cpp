class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum=0, sum_max=INT_MIN, sum_min=INT_MAX, cur_min=0, cur_max=0;
        for(int i:nums){
            total_sum += i;
            
            cur_max = max(cur_max+i, i);
            sum_max = max(cur_max, sum_max);
            
            cur_min = min(cur_min+i, i);
            sum_min = min(cur_min, sum_min);
        }
        if(total_sum == sum_min) return sum_max;
        return max(sum_max, total_sum - sum_min);
    }
};
