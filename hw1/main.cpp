#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include"dictionary.h"
#include"puzzle.h"
using namespace std;
const string PRINT_OPT="--print";
const string PRINT_COORDINATES_OPT="--print_coordinates";
const string PRINT_NUMBERED_OPT="--print_numbered";
int main(int argc, char ** argv){
    Dictionary dict;
    Puzzle puzzle;
    if(argc - 1 < 2){
        cerr<<"at least two arguments is needed"<<endl;
        exit(1);
    }
    if(argc - 1 > 3){
        cerr<<"accep almost two arguments "<<endl;
        exit(1);
    }
    puzzle.load_from_file(argv[1]);
    dict.load_from_file(argv[2]);
    puzzle.walk();
    if(argc-1 == 2){
        if(puzzle.validate_by_dict(dict)){
            cout<<"valid crossword puzzle\n";
        }
    }
    else{
        if(argv[3] == PRINT_OPT){
            puzzle.print();
        }
        else if(argv[3] == PRINT_COORDINATES_OPT){
            puzzle.print();
            cout<<endl;
            puzzle.print_coordinates();
        }
        else if(argv[3] == PRINT_NUMBERED_OPT){
            puzzle.print(true);
            cout<<endl;
            puzzle.print_numbered();
        }
    }
    return 0;
}
