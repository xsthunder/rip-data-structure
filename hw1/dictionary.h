#ifndef XSTHUNDER_DICTIONARY_H
#define XSTHUNDER_DICTIONARY_H
#include<vector>
#include<string>
using namespace std;
class Dictionary{
    public :
        void load_from_file(const string & filename);
        /* return false if word contain puns */
        static bool is_valid_word(const string& s);
        /* return true if word is in dictionary */
        bool lookup_word(const string &word) const;
        static void lower_word(string &word);
    private :
        vector<string> words;// we should use set here for the best efficiency
};
#endif
