class Solution {
public:
    static bool comp(const string& a, const string& b) {
        return a.size() > b.size();
    }
    
    bool checkSubstr(string& s1, string& s2){
        int i1=0, i2=0;
        
        while(i1<s1.size() && i2<s2.size()){
            if(s1[i1] == s2[i2]) i1++;
            i2++;
        }
        return i1 == s1.size();
    }
    
    bool checkLengthSub(vector<string>& strs, string& str, int idx){
        for(int i=0; i<=idx; i++)
            if(checkSubstr(str, strs[i])) return true;
        return false;
    }
    
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> m;
        for(string s:strs) m[s]++;
        sort(strs.begin(), strs.end(), comp);
        for(int i=0; i<strs.size(); i++){
            if(m[strs[i]] > 1)  continue;
            if(!checkLengthSub(strs, strs[i], i-1)) return strs[i].size();
        }
        return -1;
    }
};
