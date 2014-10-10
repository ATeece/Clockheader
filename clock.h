#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <time.h>
#include <iomanip>
#include <sstream>

class Clock
{
    public:
        Clock(); //base constructor
        Clock(Clock&); //copy constructor
        Clock(int, int, int); //constructor, takes 3 ints, h:m:s format
        Clock(std::string); //string-based constructor, takes "hh:mm:ss" and "hh:mm" format
        virtual ~Clock(); //blank destructor
        void local(); //fetches system time and converts it to local time
        void gmt(); //fetches system time and converts to GMT

        //getters and setters, should act as expected, setClock(Clock, int, int, int) sets a named clock
        int getHour() const { return hour; }
		int getMin() const { return min; }
		int getSec() const { return sec; }
		void setHour(int);
        void setMin(int);
        void setSec(int);
        void setClock(int, int, int);
        void setClock(Clock, int, int, int);
        void setClock(std::string);
    protected:
    private:
        int hour;
        int min;
        int sec;
};

bool operator==(const Clock a, const Clock b);
bool operator!=(const Clock a, const Clock b);
Clock operator+(Clock a, const Clock b);
Clock operator-(Clock a, const Clock b);
std::ostream& operator<<(std::ostream& out, const Clock& a); //outputs hh:mm:ss

#endif
