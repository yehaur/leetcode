class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=INT_MIN, n=nums.size();
        for(int k=0; k<n; k++){
            int start=(n-k)%n, end=n-k-1, cur=start, ind=0, tmp=(n-1)*nums[end];
            while(cur != end){
                tmp += ind*nums[cur];
                cur = (cur+1) % n;
                ind++;
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};
