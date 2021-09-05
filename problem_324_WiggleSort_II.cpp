class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        int n=nums.size(), llen=n/2+n%2, rlen=n-llen;
        vector<int> m(n, 0);
        
        int pos = 1;
        for(int i=0; i<rlen; i++){
            m[pos] = nums[i];
            pos += 2;
        }
        
        pos = 0;
        for(int i=rlen; i<n; i++){
            m[pos] = nums[i];
            pos += 2;
        }
        
        for(int i=0; i<n; i++) nums[i] = m[i];
    }
};
