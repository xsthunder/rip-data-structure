// File: time.h
// Purpose: Header file with declaration of the Time class, including
// member functions and private member variables.
class Time{
    public:
        Time();
        Time(int aHour, int aMinute, int aSecond);

        // ACCESSORS
        int getHour() const;
        int getMinute() const;
        int getSecond() const;

        // MODIFIERS
        void setHour(int aHour);
        void setMinute(int aMinute);
        void setSecond(int aSecond);

        // other member functions that operate on time objects
        bool isEqual(const Time &time2) const;
    private:
        int hour;
        int minute;
        int second;
};
