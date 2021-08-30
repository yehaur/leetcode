class Solution {
public:
    void calc(unordered_map<int, unordered_set<char>>& m, string& s, vector<string>& ans, int pos, string& ds){
        if(s.size()==ds.size()){
            ans.push_back(s);
            return;
        }
        
        for(auto a:m[ds[pos]-'0']){
            s.push_back(a);
            calc(m, s, ans, pos+1, ds);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        string s = "";
        unordered_map<int, unordered_set<char>> m;
        m[2] = {'a', 'b', 'c'};
        m[3] = {'d', 'e', 'f'};
        m[4] = {'g', 'h', 'i'};
        m[5] = {'j', 'k', 'l'};
        m[6] = {'m', 'n', 'o'};
        m[7] = {'p', 'q', 'r', 's'};
        m[8] = {'t', 'u', 'v'};
        m[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        
        calc(m, s, ans, 0, digits);
        return ans;
    }
};
