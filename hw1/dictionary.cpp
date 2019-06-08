#include<vector>
#include<string>
#include<fstream>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<cstdlib>
#include"dictionary.h"
using namespace std;
void Dictionary::load_from_file(const string& filename){
    fstream fs; /* @see http://www.cplusplus.com/reference/fstream/fstream/open/ */
    fs.open(filename.c_str(), fstream::in);
    if(!fs.is_open()){
        cerr<<"failed to open "<<filename<<endl;
        exit(1);
    }
    string s;
    while(fs>>s){
        if(Dictionary::is_valid_word(s)){
            Dictionary::lower_word(s);
            this->words.push_back(s);
        }
    }
    // cout<<words.size()<<endl;
    sort(this->words.begin(), this->words.end());
    fs.close();
}
bool Dictionary::is_valid_word(const string& s){
    for(const char &c : s){ /* use flag --std=c++11 */
        if(!isalpha(c)){
            return false;
        }
    }
    return true;
}
void Dictionary::lower_word(string& s){
    for(auto it=s.begin(); it!=s.end(); it++){/* use flag --std=c++11 */
        *it = tolower(*it);
    }
}
bool Dictionary::lookup_word(const string& s)const {
    // auto it = lower_bound(this->words.begin(), this->words.end(), s);
    // if(it != this->words.end())cout<<*it<<endl;
    return binary_search(this->words.begin(), this->words.end(), s);
}
