#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

void handle(string& s){
    if(s.size() && s[0]=='<') s.erase(0, 1);
    if(s.size() && s.back()=='>') s.pop_back();
    
    /*int double_quote_pos = s.find('"');
    while(double_quote_pos != string::npos){
        s.erase(double_quote_pos, 1);
        double_quote_pos = s.find('"');
    }*/
    
    int spaces_equal_sign = s.find('=');
    if(spaces_equal_sign != string::npos){
        s[spaces_equal_sign] = ':';
        if(s[spaces_equal_sign-1] == ' ')
            s.erase(spaces_equal_sign-1, 1);
        if(s[spaces_equal_sign] == ' ')
            s.erase(spaces_equal_sign, 1);
        handle(s);
        spaces_equal_sign = s.find(':');
        s[spaces_equal_sign] = '=';
    }
}

class Tags{
public:
    string name;
    unordered_map<string, string> attrs;
    unordered_set<Tags*> kids;
    Tags(string& nm):name(nm){};
    Tags(Tags* tag){
        name = tag->name;
        for(auto a:tag->attrs)
            attrs.insert(a);
        for(auto a:tag->kids)
            kids.insert(new Tags(a));
    };
};
/*string outcome(string s, std::vector<string> v,
            std::unordered_map<string, std::unordered_map<string, string>>& tags){
    if(s.empty()) return "Not Found!";
    int pos_wave = s.find('~');
    int pos_dot = s.find('.');
    if(pos_wave == string::npos) return "Not Found!";
    
    if(pos_dot == string::npos){
        string tag_name = s.substr(0, pos_wave);
        string attr = s.substr(pos_wave+1);
        if(!tags.count(tag_name) || !tags[tag_name].count(attr))
            return "Not Found!";
        else  
            return tags[tag_name][attr];
    }else{
        string tag_name = s.substr(0, pos_dot);
        auto it = find(v.begin(), v.end(), tag_name);
        if(it == v.end())
            return "Not Found!";
        s.erase(0, pos_dot+1);
        v.erase(v.begin(), ++it);
        return outcome(s, v, tags);
    }
    return "Not Found!";
}*/

int main() {
    string s, tag_name;
    int N(-1), Q(-1), ln(0);
    std::stack<string> tag_realtion;
    //std::unordered_map<string, string> nest_relation;
    std::unordered_map<string, Tags*> tags;
    while(cin){
        getline(cin, s);
        if(N < 0){
            int pos = s.find(' ', 0);
            N = stoi(s.substr(0, pos));
            Q = stoi(s.substr(pos));
            //std::cout << N << " == " << Q << "\n";
        }else if(ln <= N){
            handle(s);
            int tag_end = s.find('/');
            if(tag_end == string::npos){ // with tag name 
                int tag_name_pos = s.find(' ');
                tag_name = s.substr(0, tag_name_pos);
                tag_realtion.push(tag_name);
                Tags* tag = new Tags(tag_name);
                string left_str = s.substr(tag_name_pos+1);
                
                string attr, value;
                //cout << tag_name << ":\n";
                int putAttr(1), putValue(0), beginPutValue(0); 
                for(int i=0; i<left_str.size(); i++){
                    if(left_str[i] == '='){
                        putAttr = 0;
                        putValue = 1;
                    }else if(left_str[i] == '"'){
                        beginPutValue = !beginPutValue;
                        if(!beginPutValue && value.size()){
                            //cout << "    "<< attr << "=" <<value << "\n";
                            tag->attrs[attr] = value;
                            tags[tag_name] = tag;
                            putAttr = 1;
                            putValue = 0;
                            attr.resize(0);
                            value.resize(0);
                        }
                    }else{
                        if(!beginPutValue && putAttr){
                            attr.push_back(left_str[i]);
                        }
                        if(beginPutValue && putValue){
                            value.push_back(left_str[i]);
                        }
                    }
                }
            }else{ // begin find nest relation
                tag_name = s.substr(tag_end+1);
                tag_realtion.pop();
                if(!tag_realtion.empty()){
                    tags[tag_realtion.top()]->kids.insert(new Tags(tags[tag_name]));
                    tags.erase(tag_name);
                }
            }
        }else{//begin to query
            if(ln==N+1) {
                for(auto a: tags){
                    cout << a.first << ": \n";
                    cout << "Has kids: ";
                    for(auto b:a.second->kids)
                        cout << b->name << " ";
                    cout << "\n";
                    for(auto c:a.second->attrs)
                        cout<<"    "<<c.first << "="<<c.second << "\n";
                } 
            }
            //cout << outcome(s, tag_realtion, tags) << "\n";
        }
        ln++;
        if(ln > N+Q) break;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
