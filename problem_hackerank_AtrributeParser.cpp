// from https://www.hackerrank.com/challenges/attribute-parser/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

void handle(string& s){
    if(s.size() && s[0]=='<') s.erase(0, 1);
    if(s.size() && s.back()=='>') s.pop_back();
    int double_quote_pos = s.find('"');
    while(double_quote_pos != string::npos){
        s.erase(double_quote_pos, 1);
        double_quote_pos = s.find('"');
    }
}

string outcome(string s, std::vector<string> v,
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
}

int main() {
    string s, tag_name;
    int N(-1), Q(-1), ln(0);
    std::stack<string> tag_realtion;
    std::unordered_map<string, string> nest_relation;
    std::unordered_map<string, std::unordered_map<string, string>> tags;
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
                string left_str = s.substr(tag_name_pos+1);
                
                string attr, value;
                int putAttr(1), putValue(0); 
                for(int i=0; i<left_str.size(); i++){
                    if(left_str[i] == '='){
                        putAttr = 0;
                        putValue = 1;
                    }else{
                        if(left_str[i]!=' ' && putAttr){
                            attr.push_back(left_str[i]);
                        }
                        if(left_str[i]!=' ' && putValue){
                            value.push_back(left_str[i]);
                        }
                        if((left_str[i]==' '||i==left_str.size()-1) && value.size()){
                            tags[tag_name][attr] = value;
                            putAttr = 1;
                            putValue = 0;
                            attr.resize(0);
                            value.resize(0);
                        }
                    }
                }
            }else{ // begin find nest relation
                tag_name = s.substr(tag_end+1);
                while(!tag_realtion.empty()){
                    if(tag_realtion.top() == tag_name){
                        tag_realtion.pop();
                    }else{
                        nest_relation[tag_realtion.top()] = tag_name;
                        break;
                    }
                }
            }  
        }else{//begin to query
            //cout << outcome(s, tag_realtion, tags) << "\n";
        }
        ln++;
        if(ln > N+Q) break;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
