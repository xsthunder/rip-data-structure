#ifndef team_prifile_h
#define team_prifile_h
#include<string>
using namespace std;
class TeamProfile{
    public:
        string name;
        int total;
        int win;
        int loss;
        TeamProfile(const string &_name):name(_name), total(0), win(0), loss(0){}
        TeamProfile()=default;
        double get_percentage()const {return double(win)/total;}
};
#endif
