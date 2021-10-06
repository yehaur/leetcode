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
// TLE above

// Copy others who solve it by math 
class Solution {
public:
    long long int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans += i*nums[i];
        }
        int index=n-1;
        int res=ans;
        for(int k=1;k<n;k++){
            ans = ans - ((n-1)*nums[index]) + (sum-nums[index]);  // Sum(k+1) = Sum(k) - (n-1)nums[n-1] + (sum(nums) - nums[n-1])
            res=max(res,ans);
            index--;
        }
        return res;
    }
};
