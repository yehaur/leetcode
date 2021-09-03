class Solution {
public:
    int calPrev(unordered_map<int, unordered_set<int>>& m, vector<int>& visit, int pos){
        if(visit[pos]) return 0;
        
        int res = 0;
        visit[pos] = 1;
        for(auto a=m[pos].begin(); a!=m[pos].end(); a++)
            res = max(res, 1 + calPrev(m, visit, *a));
        //visit[pos] = 0;
        return res;
    }
    
    int calNext(const vector<int>& nums, vector<int>& visit, int pos){
        if(visit[pos]) return 0;
        
        int res = 1;
        visit[pos] = 1;
        res += calNext(nums, visit, nums[pos]);
        //visit[pos] = 0;
        return res;
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans=0;
        vector<int> visit(n, 0);
        unordered_map<int, unordered_set<int>> m; // (to, from)
        for(int i=0; i<n ;i++)
            m[nums[i]].insert(i);

        for(int i=0; i<nums.size(); i++)
            ans = max(ans, calPrev(m, visit, nums[i])+calNext(nums, visit, nums[i]));
        return ans;
    }
};
