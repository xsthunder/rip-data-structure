#include<vector>
#include<string>
#include<fstream>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<cassert>
#include"puzzle.h"
#include"dictionary.h"
using namespace std;
void Puzzle::load_from_file(const string& filename){
    fstream fs; /* @see http://www.cplusplus.com/reference/fstream/fstream/open/ */
    fs.open(filename.c_str(), fstream::in);
    if(!fs.is_open()){
        cerr<<"failed to open "<<filename<<endl;
        exit(1);
    }
    string s;
    this->rows=0;
    while(fs>>s){
        this->puzzle.push_back(s);
        this->cols=s.size();
        this->rows++;
    }
    // cout<<this->cols<<" "<<this->rows<<endl;
    fs.close();
}
void clear_resize_words(vector<vector<string> >&words, int rows ,int cols){
    words.resize(rows);
    for(auto it_row=words.begin() ; it_row != words.end();it_row++){
        it_row->clear();
        it_row->resize(cols);
    }
}
void Puzzle::walk(){
    vector<vector<bool> > not_reached(this->rows); // two dimension array, false means not reached yet in col
    for(auto it=not_reached.begin();it!=not_reached.end();it++){
        it->resize(this->cols, true); // initial with true value
    }
    clear_resize_words(this->row_words, this->rows, this->cols);
    clear_resize_words(this->col_words, this->rows, this->cols);
    string row_word, col_word;
    for(int r = 0;r<this->rows;r++){
        row_word.clear();
        int start_row_word_c = 0;
        for(int c = 0;c<this->cols;c++){
            // go across
            if(this->puzzle[r][c] != '#'){
                if(row_word.empty()){
                    start_row_word_c = c;
                }
                row_word.push_back(this->puzzle[r][c]);
            }
            else if(row_word.size()){
                if(row_word.size()>=2){
                    this->row_words[r][start_row_word_c]=row_word;
                    start_row_word_c = 0;
                    // cout<<row_word<<endl;
                }
                row_word.clear();
            }
            if(not_reached[r][c] && this->puzzle[r][c] != '#'){
                // go down
                col_word.clear();
                for(int j = r;j<this->rows&&this->puzzle[j][c] != '#';j++){
                    col_word.push_back(this->puzzle[j][c]);
                    not_reached[j][c] = false;
                }
                if(col_word.size()>=2){
                    // cout<<col_word<<endl;
                    this->col_words[r][c]=col_word;
                }
            }
        }
        if(row_word.size()>=2){
            this->row_words[r][start_row_word_c]=row_word;
            start_row_word_c = 0;
            // cout<<row_word<<endl;
        }
        row_word.clear();
    }
}
bool validate_word(const Dictionary& dict, const string& s){
    if(!s.empty()){
        // cout<<s<<endl;
        if(!dict.lookup_word(s)){
            cout<<"'"<<s<<"'"<<" is not a word\n";
            return false;
        }
    }
    return true;
}
bool Puzzle::validate_by_dict(const Dictionary& dict)const {
    bool validate = true;
    for(int r=0;r<this->rows;r++){
        for(int c=0;c<this->cols;c++){
            validate &= validate_word(dict, row_words[r][c]);
            validate &= validate_word(dict, col_words[r][c]);
        }
    }
    return validate;
}
void print_spliter_line(int cols){
    cout<<'+';
    for(int c = 0;c<cols;c++){
        cout<<"----+";
    }
    cout<<endl;
}
void Puzzle::print(bool print_number)const{
    // first line
    print_spliter_line(this->cols);
    // end first line
    int cnt = 0;
    for(int r = 0;r<this->rows;r++){
        for(int i=0;i<2;i++){
            cout<<'|';
            for(int c=0;c<this->cols;c++){
                char x=' ';
                if(this->puzzle[r][c]=='#'){
                    x='#';
                }
                else {
                    x=' ';
                }
                for(int j=0;j<4;j++){
                    if(i == 0 && j == 0 && print_number
                            && (
                                !this->row_words[r][c].empty() 
                                || !this->col_words[r][c].empty())
                               ){
                            cout<<++cnt;
                    }
                    else {
                        cout<<x;
                    }
                }
                cout<<'|';
            }
            cout<<endl;
        }
        print_spliter_line(this->cols);
    }
}
void Puzzle::print_coordinates()const{
    this->__print_coordinates(this->row_words, this->ACROSS);
    this->__print_coordinates(this->col_words, this->DOWN);
}
void Puzzle::__print_coordinates(const Puzzle::Words & words, const char * direction)const{
    for(int r = 0;r<this->rows;r++){
        for(int c=0;c<this->cols;c++){
            const string & s = words[r][c];
            if(!words[r][c].empty() ){
                cout<<"("<<r<<","<<c<<")"<<" "<<direction<<" "<<s<<endl;;
            }
        }
    }
}
void Puzzle::print_numbered()const{
    this->__print_numbered(this->row_words, this->ACROSS);
    cout<<endl;
    this->__print_numbered(this->col_words, this->DOWN);
}
void Puzzle::__print_numbered(const Puzzle::Words & words, const char * direction)const{
    cout<<direction<<endl;
    int cnt = 0;
    for(int r = 0;r<this->rows;r++){
        for(int c=0;c<this->cols;c++){
            const string & s = words[r][c];
            if(!words[r][c].empty() ){
                cout<<++cnt<<" "<<s<<endl;
            }
        }
    }
}
