#ifndef XSTHUNDER_PUZZLE_H
#define XSTHUNDER_PUZZLE_H
#include<vector>
#include<string>
#include"dictionary.h"
using namespace std;
class Puzzle{
    public :
        typedef vector<vector<string> > Words;
        void walk();
        void load_from_file(const string & filename);
        bool validate_by_dict(const Dictionary &dict)const ;
        void print(bool print_number=false)const;
        void print_coordinates() const;
        void print_numbered() const;
    private :
        int rows;
        int cols;
        const char *ACROSS = "ACROSS";
        const char *DOWN = "DOWN";
        vector<string> puzzle;
        // use list to store words for best efficiency
        Words row_words; // store row word starting from i,j
        Words col_words; // store col word starting from i,j
        void __print_coordinates(const Words &words, const char*) const;
        void __print_numbered(const Words &words, const char*) const;
};
#endif
