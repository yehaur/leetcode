class Solution {
public:
    bool comb(vector<int>& v1, vector<int>& v2, int pos, int target){
        int total2 = accumulate(v2.begin(), v2.end(), 0);
        if(total2 == target) return true;
        if(pos == v1.size()) return false;
        
        for(int i=pos; i<v1.size(); i++){
            v2.push_back(v1[i]);
            bool tmp = comb(v1, v2, i+1, target);
            if(tmp) return true;
            v2.pop_back();
        }
        return false;
    }
    
    bool canPartition(vector<int>& nums) {
        int n(nums.size());
        if(n == 1) return false;
        int total(0);
        for(int i:nums) total += i; cout << total << "\n";
        if(total%2) return false;
        vector<int> v;
        
        return comb(nums, v, 0, total/2);
    }
};
