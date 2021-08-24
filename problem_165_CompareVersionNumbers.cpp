class Solution {
public:
    int comp(string& s1, string& s2){
        if(s1 == s2) return 0;
        
        while(!s1.empty() && s1[0]=='0') s1.erase(s1.begin());
        while(!s2.empty() && s2[0]=='0') s2.erase(s2.begin());
        int i1=0, i2=0, c1=1, c2=1;
        while(s1.size()){
            i1 += c1*(s1.back()-'0');
            s1.pop_back();
            c1 *= 10;
        }
        while(s2.size()){
            i2 += c2*(s2.back()-'0');
            s2.pop_back();
            c2 *= 10;
        }
        
        if(i1 < i2) return -1;
        if(i1 > i2) return 1;
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        string v1(version1), v2(version2);
        
        size_t ps1=v1.find('.'), ps2=v2.find('.');
        while(!v1.empty() || !v2.empty()){
            string tmp_v1, tmp_v2;
            if(ps1!=string::npos) {
                tmp_v1=v1.substr(0, ps1);
                v1 = v1.substr(ps1+1);
            }else{
                tmp_v1 = v1;
                v1 = "";
            }
            
            if(ps2!=string::npos){
                tmp_v2=v2.substr(0, ps2);
                v2 = v2.substr(ps2+1);
            }else{
                tmp_v2 = v2;
                v2 = "";
            }
            int res = comp(tmp_v1, tmp_v2);
            if(res) return res; 
            
            ps1 = v1.find('.');
            ps2 = v2.find('.');
        }
        
        return 0;
    }
};
