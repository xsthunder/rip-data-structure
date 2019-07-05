// 找众数
#include<iostream>
#include<fstream>
#include<map>
#include<utility>
using namespace std;
int main(int argc, char** argv){
    int x;
    map<int, int> m;
    if( argc -1 != 1){
        cout<<"Usage "<<argv[0]<<" input file" <<endl
            <<"intput file contain integers splited by space"<<endl;
        return 1;
    }
    fstream fin;
    fin.open(argv[1], fstream::in);
    if(!fin.is_open()){
        cout<<"can NOT open"<<argv[1]<<endl;
        return 1;
    }
    while(fin>>x){
        auto it = m.find(x);
        int cnt = 1;
        if( it!=m.end() ){
            cnt += it->second;
            m.erase(it);
        }
        m.insert(make_pair(x, cnt));
    }
    int mxcnt = 0;
    for(auto p:m){
        if(mxcnt < p.second){
            mxcnt = p.second;
        }
    }
    for(auto p:m){
        if(mxcnt == p.second){
            cout<<p.first<<" ";
        }
    }
    cout<<endl;
    return 0;
}
