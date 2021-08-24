class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);
        map<int, vector<int>> m;
        for(int i=0; i<n;i++){
            m[intervals[i][0]].push_back(intervals[i][1]);
            m[intervals[i][0]].push_back(i);
        }
        
        for(int i=0; i<n; i++){
            auto iter = m.find(intervals[i][1]);
            if(iter != m.end())
                ans[i] = iter->second[1];
            else{
                auto iter_upper = m.upper_bound(intervals[i][1]);
                if(iter_upper != m.end())
                    ans[i] = iter_upper->second[1];
            }       
        }
        return ans;
    }
};
