#include"Match.h"
#include<vector>
#include<cassert>
#include<utility>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include"TeamProfile.h"
#include<limits>
#include<map>
using namespace std;
const string Match::spliter = "   ";
istream & read_n_number (istream & in, vector<int> &v, const int n = 6){
    for(int i =0;i<n;i++){
        int x;
        in>>x;
        v.push_back(x);
    }
    return in;
}
istream & operator >> (istream & in, Match & m){
    in>>m.day>>m.month>>m.date>>m.year;
    in>>m.hostname;
    read_n_number(in, m.hostpoint);
    in>>m.guestname;
    read_n_number(in, m.guestpoint);
    m.diff_point = abs( *m.hostpoint.rbegin() - *m.guestpoint.rbegin() );
    m.total_point = ( *m.hostpoint.rbegin() + *m.guestpoint.rbegin() );
    return in;
}

class MatchPointCmp{
    public :
        typedef Match::vector_const_iterator item;
        bool operator() (const item &pa, const item &pb){
            const Match &a = *pa;
            const Match &b = *pb;
            return a.diff_point != b.diff_point ?
                a.diff_point < b.diff_point : (
                            a.total_point != b.total_point ?
                            a.total_point > b.total_point : (
                                a.guestname != b.guestname ?
                                a.guestname < b.guestname :(
                                        a.hostname < b.hostname
                                    )
                            )
                        );
        }
};
int get_max_name_width(const vector<Match> &ms){
    int max_name_width = 0;
    for(Match::vector_const_iterator it=ms.cbegin();it!=ms.cend();it++){
        max_name_width = max(max_name_width, (int)(it->hostname).size());
        max_name_width = max(max_name_width, (int)(it->guestname).size());
    }
    return max_name_width;
}
void print_total(ostream &out, const vector<Match> &ms){
    vector<Match::vector_const_iterator >vp;
    const string & spliter = Match::spliter;
    const int max_name_width = get_max_name_width(ms);
    for(Match::vector_const_iterator it=ms.cbegin();it!=ms.cend();it++){
        vp.push_back(it);
    }
    sort(vp.begin(), vp.end(), MatchPointCmp()); // sort iterator to avoid copy
    out<<"ALL GRAMS, SORTED BY POINTS DIFFERNTIAL:\n";
    for(const auto &mp:vp){
        const auto &m = *mp;
        out<<left<<setw(max_name_width)<<m.hostname;
        if(*m.hostpoint.rbegin()> *m.guestpoint.rbegin()){
            // host wins 
            out<<spliter<<"defeated";
        }
        else {
            out<<spliter<<"lost to ";
        }
        out<<spliter<<left<<setw(max_name_width)<<m.guestname;
        out<<spliter<<setw(2)<<*m.hostpoint.rbegin()<<" - "<<setw(2)<<*m.guestpoint.rbegin();
        out<<spliter<<"differential =";
        out<<spliter<<setw(2)<<m.diff_point;
        out<<spliter<<"total points = ";
        out<<spliter<<setw(2)<<m.total_point;
        out<<endl;
    }
}
bool feq(float f1, float f2){
        return fabs(f1 - f2) < numeric_limits<float>::epsilon();
}
class PercentageCmp{
    public:
        bool operator()(const TeamProfile &a, const TeamProfile &b){
            if(feq(a.get_percentage(), b.get_percentage())){
                return a.total != b.total ?(
                        a.total > b.total
                        ):(
                            a.name < b.name
                          );
            }
            else {
                return a.get_percentage() > b.get_percentage();
            }
        }
};
void print_percentage(ostream& out, const vector<Match> &ms){
    const int max_name_width = get_max_name_width(ms);
    const string & spliter = Match::spliter;
    map<string, TeamProfile> mtp;
    for(const auto &m:ms){
        if(mtp.find(m.hostname) == mtp.end()){
            mtp[m.hostname] = TeamProfile(m.hostname);
        }
        if(mtp.find(m.guestname) == mtp.end()){
            mtp[m.guestname] = TeamProfile(m.guestname);
        }
        mtp[m.hostname].total++;
        mtp[m.guestname].total++;
        if(*m.hostpoint.rbegin() > *m.guestpoint.rbegin()){
            // host wins
            mtp[m.hostname].win++;
            mtp[m.guestname].loss++;
        }
        else {
            mtp[m.hostname].loss++;
            mtp[m.guestname].win++;
        }
    }
    vector<TeamProfile> vtp;
    for(const auto & p :mtp){
        vtp.push_back(p.second);
    }
    sort(vtp.begin(), vtp.end(), PercentageCmp());
    out<<"ALL TEAMS, SORTED BY WIN PERCENTAGE:\n";
    for(const auto &team:vtp){
        out<<left<<setw(max_name_width)<<team.name;
        out<<spliter;
        out<<setw(2)<<team.win<<" win(s)"<<" - "<<setw(2)<<team.loss<<" loss(es)";
        out<<spliter;
        out<<fixed<<setprecision(2)<<team.get_percentage()<<endl;
    }
}
void print_creative(ostream& out, const vector<Match> &ms){
    out<<"TODO implement print_creative"<<endl;
}
