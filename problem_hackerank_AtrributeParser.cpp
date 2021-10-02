// from https://www.hackerrank.com/challenges/attribute-parser/problem

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
    if(s.size() && (s[0]=='<' || s[0]==' ')) s.erase(0, 1);
    if(s.size() && (s.back()=='>' || s.back()==' ')) s.pop_back();
    
    int spaces_equal_sign = s.find('=');
    if(spaces_equal_sign != string::npos){
        s[spaces_equal_sign] = ':';
        if(s[spaces_equal_sign-1] == ' ')
            s.erase(spaces_equal_sign-1, 1);
        spaces_equal_sign = s.find('=');
        if(s[spaces_equal_sign+1] == ' ')
            s.erase(spaces_equal_sign+1, 1);
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

void outcome(string headstr, string leftstr, Tags* tags, string& attr){
        if(!tags){
            std::cout << "Not Found!\n";
            return;
        }
        
        if(leftstr.empty()){
            if(!tags->attrs.count(attr))
                std::cout << "Not Found!\n";
            else 
                std::cout << tags->attrs[attr] << "\n";
            return;
        }
        
        int pos_dot = leftstr.find('.');
        string new_headstr = leftstr.substr(0, pos_dot); 
        string new_left = leftstr.substr(pos_dot+1);
        if(pos_dot == string::npos){
            new_headstr = leftstr;
            new_left = "";
        }
        for(auto kid:tags->kids){
            if(kid->name == new_headstr){
                //std::cout << kid->name << "=>" << new_left << "\n";
                outcome(new_headstr, new_left, kid, attr);
                return;
            }
        }
        std::cout << "Not Found!\n";            
}

int main() {
    string s, tag_name;
    int N(-1), Q(-1), ln(0);
    std::stack<string> tag_realtion;
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
                if(tag_name_pos != string::npos)
                    tag_name = s.substr(0, tag_name_pos);
                else 
                    tag_name = s;
                tag_realtion.push(tag_name);
                Tags* tag = new Tags(tag_name);
                string left_str = s.substr(tag_name_pos+1);
                if(tag_name_pos == string::npos)
                    left_str = "";
                
                string attr, value;
                //cout << tag_name << ": "<< left_str << "\n";
                int putAttr(1), putValue(0), beginPutValue(0); 
                for(int i=0; i<left_str.size(); i++){
                    if(left_str[i] == '='){
                        putAttr = 0;
                        putValue = 1;
                    }else if(left_str[i] == '"'){
                        beginPutValue = !beginPutValue;
                        if(!beginPutValue && value.size()){
                            //cout << "    "<< attr << "=" <<value << "\n";
                            handle(attr);
                            handle(value);
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
                if(left_str.empty())
                    tags[tag_name] = tag;
            }else{ // begin find nest relation
                tag_name = s.substr(tag_end+1);
                tag_realtion.pop();
                if(!tag_realtion.empty()){
                    tags[tag_realtion.top()]->kids.insert(new Tags(tags[tag_name]));
                    tags.erase(tag_name);
                }
            }
        }else{//begin to query
            int pos_wave = s.find('~'), pos_dot=s.find('.');
            string valstr = s.substr(pos_wave+1);
            if(pos_dot != string::npos){
                string headstr = s.substr(0, pos_dot);
                string leftstr = s.substr(pos_dot+1, pos_wave-pos_dot-1);
                outcome(headstr, leftstr, tags[headstr], valstr);
            }else{
                string headstr = s.substr(0, pos_wave);
                if(!tags.count(headstr) || !tags[headstr]->attrs.count(valstr))
                    std::cout << "Not Found!\n";
                else
                    std::cout << tags[headstr]->attrs[valstr] << "\n"; 
            }
        }
        ln++;
        if(ln > N+Q) break;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
