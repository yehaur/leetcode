class Solution {
public:
    int summ(map<int, int>& m){
        int ans = 0;
        for(auto it=m.begin(); it!=m.end(); it++)
            ans += it->second;
        return ans;
    }
    bool calc(map<int, int>& m, int len, int cnt, int side){
        if(!summ(m) && len==side && cnt==4) return true;
        if(len<0 || cnt>4) return false;
        
        auto it = m.begin();
        while(it!=m.end() && it->first<=len){
            if(it->second){
                it->second--;
                bool tmp1=false, tmp2=false;
                if(len == it->first)
                    tmp1 = tmp1 || calc(m, side, cnt+1, side);
                else
                    tmp2 = tmp2 || calc(m, len-it->first, cnt, side);
                it->second++;
                if(tmp1 || tmp2) return true;
            }
            it++;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int totallen = std::accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(totallen%4) return false;
        
        int sidelen = totallen/4;
        map<int, int> m;
        for(int a:matchsticks) m[a]++;
        return calc(m, sidelen, 0, sidelen);
    }
};
