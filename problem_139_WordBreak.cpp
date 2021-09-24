class Solution {
public:
    unordered_map<string, bool> m;
    bool solve(string s, unordered_set<string>& us){
        if(m.count(s)) return m[s];
        if(us.count(s)) return m[s]=true;
        
        for(int i=1; i<=s.size(); i++){
            string sl = s.substr(0, i);
            string sr = s.substr(i);
            if(us.count(sr) && solve(sl, us))
                return m[s] = true;
        }
        return m[s] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        return solve(s, us);
    }
};
