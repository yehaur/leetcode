class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int ans=0, n=nums.size(), nmin=0, nmax=0;
        for(int i=0; i<n; i++){
            if(nums[i]){
                nmin = nums[i];
                nmax = nums[n-1];
                break;
            }
        }
        if(!nmin || nmax<nmin) return ans;
        
        vector<int> v(nmax+1, 0);
        for(int i:nums) if(i) v[i]++;
        
        for(int i=nmin; i<=nmax; i++){
            if(!v[i]) continue;
            if(v[i] > 2) ans += v[i]*(v[i]-1)*(v[i]-2)/6;
        }
        
        for(int i=nmin; i<=nmax; i++){
            if(!v[i]) continue;
            for(int j=i+1; j<=nmax; j++){
                if(!v[j]) continue;
                if(v[i]>1 && 2*i>j) ans += v[i]*(v[i]-1)/2*v[j];
                if(v[j]>1) ans += v[j]*(v[j]-1)/2*v[i];
                ans += v[i]*v[j]*std::accumulate(v.begin()+j+1, v.begin()+min(nmax+1,i+j), 0);
            }
        }
        
        /*for(int i=nmin; i<=nmax; i++){
            if(!v[i]) continue;
            for(int j=i+1; j<=nmax; j++){
                if(!v[j]) continue;
                for(int k=j+1; k<=min(nmax, i+j-1); k++){
                    if(!v[k]) continue;
                    ans += v[i]*v[j]*v[k];
                }
            }
         }*/
        
         return ans;
    }
};
