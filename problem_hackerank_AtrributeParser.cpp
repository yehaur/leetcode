// from https://www.hackerrank.com/challenges/attribute-parser/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
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

string outcome(string s, std::unordered_map<string, unordered_set<string>>& relation,
            std::unordered_map<string, std::unordered_map<string, string>>& tags, 
            string key){
    if(s.empty()) return "Not Found!";
    if(key.size() && !relation.count(key)) return "Not Found!";
    
    int pos_wave = s.find('~');
    int pos_dot = s.find('.');
    //if(pos_wave == string::npos) return "Not Found!";
    
    if(pos_dot == string::npos){
        string tag_name = s.substr(0, pos_wave);
        string attr = s.substr(pos_wave+1);
        if(key.empty()&&tag_name=="tag8") cout << attr << "!!!!!!!" << relation.count("tag8")<<"\n";
        if(key.empty() && !relation.count(tag_name))
            return "Not Found!";
        else if(key.empty() && relation.count(tag_name)){
            if(!tags[tag_name].count(attr))
                return "Not Found!";
            else 
                return (tags[tag_name][attr]==""?"Not Found!":tags[tag_name][attr]);
        }else if(!relation.count(key) || !relation[key].count(tag_name))
            return "Not Found!";
        else  
            return (tags[tag_name][attr]==""?"Not Found!":tags[tag_name][attr]);
    }else{
        string tag_name = s.substr(0, pos_dot);
        s.erase(0, pos_dot+1);
        if(!relation.count(tag_name))
            return "Not Found!";
        else if(key.empty())
            return outcome(s, relation, tags, tag_name);
        else if(!relation.count(key) || !relation[key].count(tag_name))
            return "Not Found!";
        else 
            return outcome(s, relation, tags, tag_name); 
    }
    return "Not Found!";
}

int main() {
    string s, tag_name;
    int N(-1), Q(-1), ln(0);
    std::stack<string> tag_realtion;
    std::unordered_map<string, unordered_set<string>> nest_relation;
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
                        if(tag_realtion.size() == 1 && 
                            !nest_relation.count(tag_realtion.top()))
                            nest_relation[tag_realtion.top()] = {};
                        tag_realtion.pop();
                    }else{
                        nest_relation[tag_realtion.top()].insert(tag_name);
                        break;
                    }
                }
                if(ln == N){
                    
                }
            }  
        }else{//begin to query
            cout << outcome(s, nest_relation, tags, "") << "\n";
        }
        ln++;
        if(ln > N+Q) break;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
