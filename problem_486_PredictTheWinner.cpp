class Solution {
public:
    bool guess(int p1, int p2, int s1, int s2, vector<int> left){
        if(left.empty()) return s1>=s2;
        if(left.size()==1) return s1+p1*left[0] >= s2+p2*left[0];
        
        bool res;
        int f=left[0], b=left.back();
        if(p1){
            left.erase(left.begin());
            res = guess(0, 1, s1+f, s2, left);
            left.insert(left.begin(), f);
            if(res) return true;
            left.pop_back();
            res = res || guess(0, 1, s1+b, s2, left);
            left.push_back(b);
        }else{
            left.erase(left.begin());
            res = guess(1, 0, s1, s2+f, left);
            left.insert(left.begin(), f);
            if(res) return true;
            left.pop_back();
            res = res || guess(1, 0, s1, s2+b, left);
            left.push_back(b);
        }
        return res;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n(nums.size());
        
        return guess(1,0,0,0,nums);
    }
};
