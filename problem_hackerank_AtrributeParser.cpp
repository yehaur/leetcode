// from https://www.hackerrank.com/challenges/attribute-parser/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
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

string outcome(string s, std::vector<string>& v){
    if
}

int main() {
    string s, tag_name;
    int N(-1), Q(-1), ln(0);
    std::vector<string> tag_realtion;
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
                tag_realtion.push_back(tag_name);
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
            }else{ // the tag content is over here
                
            }    
        }else{//begin to query
            int dot_pos = s.find('.');
            int wave_pos = s.find('~');
            outcome(s, tag_realtion);
        }
        ln++;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
