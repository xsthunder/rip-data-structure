#include<fstream>
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include"Match.h"
using namespace std;
const string OPT_TOTAL_POINT("--total_points");
const string OPT_WIN_PERCENTAGE("--win_percentage");
const string OPT_CREATE("--creative");
void print_usage(char ** argv){
    cerr<<"Usage: "<<argv[0]<<" <input_file> <output_file> <option>"<<endl;
    cerr<<"Options: "<<OPT_TOTAL_POINT<<" "<<OPT_WIN_PERCENTAGE<<" "<<OPT_CREATE<<endl;
}
void open_or_exit(fstream & fs, char * filename, ios_base::openmode mode){
    fs.open(filename, mode);
    if(!fs.is_open()){
        cerr<<"Error: "<<"can NOT open "<<filename<<endl;
        exit(1);
    }
}
int main(int argc, char **argv){
    if(argc - 1 < 2){
        print_usage(argv);
        return 1;
    }
    fstream fin, fout;
    open_or_exit(fin, argv[1], fstream::in);
    open_or_exit(fout, argv[2], fstream::out);
    Match m;
    vector<Match> ms;
    while(fin>>m){
        ms.push_back(m);
    }
    if(argc - 1 == 2){
        print_total(fout, ms);
        print_percentage(fout, ms);
        print_creative(fout, ms);
    }
    else if(argc - 1 == 3){
        const char* option = argv[3];
        if(option == OPT_TOTAL_POINT){
            print_total(fout, ms);
        }
        else if(option == OPT_WIN_PERCENTAGE){
            print_percentage(fout, ms);
        }
        else if(option == OPT_CREATE){
            print_creative(fout, ms);
        }
        else {
            print_usage(argv);
        }
    }
    else if(argc - 1 > 3){
        cerr<<"Accept three arguments at most"<<endl;
    }
    return 0;
}
