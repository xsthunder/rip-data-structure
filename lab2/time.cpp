#include"time.h"
#include<iostream>
using namespace std;
Time::Time(){
    this->hour = this->minute = this->second = 0;
}
Time::Time(int aHour, int aMinute, int aSecond):hour(aHour),minute(aMinute), second(aSecond) {
}
int Time::getHour()const {return hour;}
int Time::getMinute()const {return minute;}
int Time::getSecond()const {return second;}
void Time::setHour(int aHour){hour=aHour;}
void Time::setMinute(int aMinute){minute=aMinute;}
void Time::setSecond(int aSecond){second=aSecond;}
void Time::PrintAMPM()const{
    if(hour <= 12){
        cout<<hour<<":"<<minute<<":"<<second<<" am";
    }
    else{
        cout<<hour-12<<":"<<minute<<":"<<second<<" pm";
    }
    cout<<endl;
}
bool IsEarlierThan(const Time &a, const Time &b){
    // 多个层叠的条件运算符^_^
    return a.getHour() != b.getHour()?
           a.getHour() < b.getHour():(
                a.getMinute() != b.getMinute()?
                a.getMinute() < b.getMinute():(
                    a.getSecond() < b.getSecond()
                    )
                );
}
