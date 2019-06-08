#ifndef XSTHUNDER_PUZZLE_H
#define XSTHUNDER_PUZZLE_H
#include<vector>
#include<string>
#include"dictionary.h"
using namespace std;
class Puzzle{
    public :
        void walk();
        void load_from_file(const string & filename);
        bool validate_by_dict(const Dictionary &dict)const ;
        void print(bool print_number=true)const;
        void print_coordinates() const;
        void print_numbered() const;
    private :
        int rows;
        int cols;
        vector<string> puzzle;// we should use set here for the best efficiency
        // use list to store words for best efficiency
        vector<vector<string> >row_words; // store row word starting from i,j
        vector<vector<string> >col_words; // store col word starting from i,j
};
#endif
