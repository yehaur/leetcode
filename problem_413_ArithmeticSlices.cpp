class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        
        int l(1), r(1), s(0);
        vector<int> v(n, 0);
        for(int i=0; i<=n-3; i++){
            if((nums[i+1]-nums[i]) == (nums[i+2]-nums[i+1]))
                v[i+2] = 1;
        }
        //for(int i:v) cout << i << " ";cout<<"\n";
        
        while(r < n){
            while(r<n && (r<=l || v[r])) r++;
            r = min(r, n);
            int num_one=accumulate(v.begin()+l, v.begin()+r, 0);
            int comb_one = (1+num_one)*num_one/2;
            s += comb_one;
            l=r;
        }
        return s;
    }
};
