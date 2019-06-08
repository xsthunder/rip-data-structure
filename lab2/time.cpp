#include"time.h"
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
