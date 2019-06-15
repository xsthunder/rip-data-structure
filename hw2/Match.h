#ifndef xsthunder_header_h
#define xsthunder_header_h
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Match{
    public:
        typedef vector<Match>::const_iterator vector_const_iterator;
        static const string spliter;
        string day;
        string month;
        int date;
        int year;
        string hostname;
        vector<int> hostpoint;
        string guestname;
        vector<int> guestpoint;
        int diff_point;
        int total_point;
};
istream & operator >> (istream & in, Match & m);
void print_total(ostream &out, const vector<Match> &ms);
void print_percentage(ostream &out, const vector<Match> &ms);
void print_creative(ostream &out, const vector<Match> &ms);
#endif
