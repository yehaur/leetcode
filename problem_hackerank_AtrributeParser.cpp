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
                tag_realtion.push_back(tag_name); cout<<tag_name<<": ";
                string left_str = s.substr(tag_name_pos+1);
                while(left_str.size()){ 
                    int equal_sign_pos = left_str.find('=');
                    int next_attr_pos = left_str.find(' ');
                    string attr = left_str.substr(0, equal_sign_pos);
                    string value = left_str.substr(equal_sign_pos+1,
                                        next_attr_pos-equal_sign_pos-1);
                    if(attr.size()){
                        tags[tag_name][attr] = value;
                        std::cout << "\t" << attr << "=" << value<<"\n";
                    }
                    left_str.erase(0, next_attr_pos);
                }
            }else{ // the tag content is over here
                //tag_realtion.push_back(tag_name);
            }    
        }else{//begin to query
            
        }
        ln++;
    }
    for(auto a:tag_realtion) cout << a<< " ";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
